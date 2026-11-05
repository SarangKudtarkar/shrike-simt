# MicroPython, runs ON the Shrike-Lite RP2040:   mpremote run host/board_run.py
# Needs on the board: shrike_simt.bin (from Go Configure) and one or more *.prog files (from tools/asm.py).
import os
import time
from machine import Pin, SPI

FLASH = True                      # set False to skip re-flashing if the FPGA is already configured
BITSTREAM = "shrike_simt.bin"

if FLASH:
    import shrike
    shrike.flash(BITSTREAM)
    time.sleep_ms(300)

# RP2040 SPI0 pins wired to the FPGA configuration/IO bus: SCK=GP2, MOSI(SI)=GP3, MISO(SO)=GP0, SS=GP1
cs = Pin(1, Pin.OUT, value=1)
spi = SPI(0, baudrate=1_000_000, polarity=0, phase=0, sck=Pin(2), mosi=Pin(3), miso=Pin(0))


def wr(addr, data):
    cs(0)
    spi.write(bytes([0x80 | addr]))
    spi.write(bytes(data))
    cs(1)


def rd(addr, n):
    buf = bytearray(n)
    cs(0)
    spi.write(bytes([addr & 0x7F]))
    spi.readinto(buf, 0x00)
    cs(1)
    return buf


def load_prog(path):
    words, data, expect = [], [], []
    with open(path) as f:
        for line in f:
            t = line.split()
            if not t:
                continue
            if t[0] == "I":
                words.append(int(t[1], 16))
            elif t[0] == "D":
                data.append([int(x) for x in t[1:]])
            elif t[0] == "E":
                expect.append([int(x) for x in t[1:]])
    return words, data, expect


def run(path):
    words, data, expect = load_prog(path)
    code = bytearray()
    for w in words:
        code.append(w & 0xFF)
        code.append(w >> 8)
    wr(0x20, code)
    wr(0x40, [0] * 32)
    for d in data:
        wr(0x40 + d[0], [x & 0xFF for x in d[1:]])
    wr(0x00, [0x01])
    for _ in range(2000):
        if rd(0x01, 1)[0] & 1:
            break
    else:
        print(path, "TIMEOUT")
        return
    c = rd(0x08, 8)
    cyc, ins, ops, con = [c[i] | (c[i + 1] << 8) for i in (0, 2, 4, 6)]
    scr = rd(0x40, 32)
    bad = 0
    for e in expect:
        for i, v in enumerate(e[1:]):
            if scr[e[0] + i] != (v & 0xFF):
                bad += 1
    util = 100.0 * ops / (ins * 2) if ins else 0.0
    print("%-24s cycles=%d instr=%d lane_ops=%d conflicts=%d util=%.1f%%  %s"
          % (path, cyc, ins, ops, con, util, "PASS" if bad == 0 else "FAIL(%d bytes)" % bad))
    print("  scratchpad:", " ".join("%02x" % b for b in scr))


if rd(0x02, 1)[0] != 0xA5:
    print("FPGA did not answer with ID 0xA5. Check: bitstream flashed? pin assignment? SPI wiring?")
else:
    for name in sorted(os.listdir()):
        if name.endswith(".prog"):
            run(name)
