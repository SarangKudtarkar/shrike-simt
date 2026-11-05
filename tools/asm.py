#!/usr/bin/env python3
"""Assembler for the shrike-simt ISA.  Usage: asm.py kernel.s -o kernel.prog

Syntax (one statement per line, ';' starts a comment):
  add/sub/mul/mac rd, rs1, rs2      addi rd, rs1, imm(-16..15)     movi rd, imm(-16..15)
  tid rd                            shri rd, rs1, imm(0..7)        relu rd, rs1
  ld rd, [rs1+imm(0..31)]           st rd, [rs1+imm(0..31)]        (st stores rd)
  slt rs1, rs2 / seq rs1, rs2       sets the per-lane predicate
  if / else / endif                 mask control (1-deep)
  loop imm(1..31) / endlp           1-deep hardware loop
  end
  .data ADDR v v ...                initial scratchpad bytes
  .expect ADDR v v ...              expected scratchpad bytes after the run
"""
import argparse
import re
import sys

OPS = {'nop': 0, 'add': 1, 'sub': 2, 'mul': 3, 'mac': 4, 'addi': 5, 'movi': 6, 'tid': 7,
       'ld': 8, 'st': 9, 'slt': 10, 'seq': 11, 'if': 12, 'else': 13, 'endif': 14,
       'loop': 15, 'endlp': 16, 'end': 17, 'shri': 18, 'relu': 19}


def reg(tok, ln):
    m = re.fullmatch(r'r([0-7])', tok.strip().lower())
    if not m:
        sys.exit(f"line {ln}: bad register '{tok}'")
    return int(m.group(1))


def imm(tok, lo, hi, ln):
    v = int(tok.strip(), 0)
    if not lo <= v <= hi:
        sys.exit(f"line {ln}: immediate {v} out of range {lo}..{hi}")
    return v & 0x1F


def word(op, rd=0, rs1=0, low=0):
    return (OPS[op] << 11) | (rd << 8) | (rs1 << 5) | (low & 0x1F)


def assemble(text):
    words, data, expect = [], [], []
    for ln, raw in enumerate(text.splitlines(), 1):
        line = raw.split(';')[0].strip()
        if not line:
            continue
        if line.startswith('.'):
            parts = line.split()
            vals = [int(x, 0) for x in parts[1:]]
            if parts[0] == '.data':
                data.append(vals)
            elif parts[0] == '.expect':
                expect.append(vals)
            else:
                sys.exit(f"line {ln}: unknown directive {parts[0]}")
            continue
        mn, _, rest = line.partition(' ')
        mn = mn.lower()
        if mn not in OPS:
            sys.exit(f"line {ln}: unknown mnemonic '{mn}'")
        args = [a.strip() for a in rest.split(',')] if rest.strip() else []
        if mn in ('add', 'sub', 'mul', 'mac'):
            w = word(mn, reg(args[0], ln), reg(args[1], ln), reg(args[2], ln) << 2)
        elif mn == 'addi':
            w = word(mn, reg(args[0], ln), reg(args[1], ln), imm(args[2], -16, 15, ln))
        elif mn == 'movi':
            w = word(mn, reg(args[0], ln), 0, imm(args[1], -16, 15, ln))
        elif mn == 'tid':
            w = word(mn, reg(args[0], ln))
        elif mn == 'shri':
            w = word(mn, reg(args[0], ln), reg(args[1], ln), imm(args[2], 0, 7, ln))
        elif mn == 'relu':
            w = word(mn, reg(args[0], ln), reg(args[1], ln))
        elif mn in ('ld', 'st'):
            m = re.fullmatch(r'\[\s*(r[0-7])\s*(?:\+\s*(\w+))?\s*\]', args[1])
            if not m:
                sys.exit(f"line {ln}: bad memory operand '{args[1]}'")
            off = imm(m.group(2), 0, 31, ln) if m.group(2) else 0
            w = word(mn, reg(args[0], ln), reg(m.group(1), ln), off)
        elif mn in ('slt', 'seq'):
            w = word(mn, 0, reg(args[0], ln), reg(args[1], ln) << 2)
        elif mn == 'loop':
            w = word(mn, 0, 0, imm(args[0], 1, 31, ln))
        else:
            w = word(mn)
        words.append(w)
    if len(words) > 16:
        sys.exit(f"program has {len(words)} instructions; instruction memory holds 16")
    return words, data, expect


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('src')
    ap.add_argument('-o', '--out', required=True)
    a = ap.parse_args()
    words, data, expect = assemble(open(a.src).read())
    with open(a.out, 'w') as f:
        for w in words:
            f.write(f"I {w:04x}\n")
        for d in data:
            f.write("D " + " ".join(str(x) for x in d) + "\n")
        for e in expect:
            f.write("E " + " ".join(str(x) for x in e) + "\n")
    print(f"{a.src}: {len(words)} instructions -> {a.out}")


if __name__ == '__main__':
    main()
