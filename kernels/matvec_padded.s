; same as matvec_relu but W row stride is 9 (padding), so lanes hit different banks
; W row0@0..7  row1@9..16   x@17..24   y@25,26
.data 0 2 255 3 0 1 2 254 1
.data 9 253 1 254 2 255 0 252 1
.data 17 4 5 1 2 6 3 2 7
.expect 25 10 0
tid  r1
add  r6, r1, r1
add  r6, r6, r6
add  r6, r6, r6
add  r6, r6, r1
loop 8
ld   r2, [r6+0]
ld   r3, [r5+17]
mac  r4, r2, r3
addi r6, r6, 1
addi r5, r5, 1
endlp
relu r4, r4
shri r4, r4, 1
st   r4, [r1+25]
end
