; y = relu(W x) >> 1   W (2x8, row stride 8) @0..15   x@16..23   y@24,25
; NOTE: row stride 8 => both lanes hit the same scratchpad bank on every W load (bank conflicts)
.data 0 2 255 3 0 1 2 254 1
.data 8 253 1 254 2 255 0 252 1
.data 16 4 5 1 2 6 3 2 7
.expect 24 10 0
tid  r1
add  r6, r1, r1
add  r6, r6, r6
add  r6, r6, r6
loop 8
ld   r2, [r6+0]
ld   r3, [r5+16]
mac  r4, r2, r3
addi r6, r6, 1
addi r5, r5, 1
endlp
relu r4, r4
shri r4, r4, 1
st   r4, [r1+24]
end
