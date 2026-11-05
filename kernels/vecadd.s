; C[i] = A[i] + B[i]   A@0..7  B@8..15  C@16..23   lane l handles i = l, l+2, ...
.data 0 3 1 4 1 5 9 2 6
.data 8 10 20 30 40 50 60 70 80
.expect 16 13 21 34 41 55 69 72 86
tid  r1
loop 4
ld   r2, [r1+0]
ld   r3, [r1+8]
add  r4, r2, r3
st   r4, [r1+16]
addi r1, r1, 2
endlp
end
