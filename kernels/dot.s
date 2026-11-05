; per-lane partial dot product.  A@0..7  B@8..15  partials@16,17 (total = p0 + p1)
.data 0 1 2 3 4 5 6 7 8
.data 8 2 4 6 8 1 3 5 7
.expect 16 60 114
tid  r1
movi r4, 0
loop 4
ld   r2, [r1+0]
ld   r3, [r1+8]
mac  r4, r2, r3
addi r1, r1, 2
endlp
tid  r1
st   r4, [r1+16]
end
