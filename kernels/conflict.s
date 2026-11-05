; out[a] = in[a] + 1 for even a; lane0 uses a=0,4,8,12 and lane1 a=2,6,10,14 => same bank every access
; in@0..15  out@16..30 (even)
.data 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
.expect 16 2
.expect 18 4
.expect 20 6
.expect 22 8
.expect 24 10
.expect 26 12
.expect 28 14
.expect 30 16
tid  r1
add  r1, r1, r1
loop 4
ld   r2, [r1+0]
addi r2, r2, 1
st   r2, [r1+16]
addi r1, r1, 4
endlp
end
