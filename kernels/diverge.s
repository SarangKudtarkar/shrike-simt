; y = (x < 10) ? 2x : x + 15    x@0..7  y@8..15   (IF/ELSE serialises both paths)
.data 0 3 15 7 22 10 9 30 1
.expect 8 6 30 14 37 25 18 45 2
tid  r1
movi r3, 10
loop 4
ld   r2, [r1+0]
slt  r2, r3
if
add  r4, r2, r2
else
addi r4, r2, 15
endif
st   r4, [r1+8]
addi r1, r1, 2
endlp
end
