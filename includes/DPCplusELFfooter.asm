; Provided under the CC0 license. See the included LICENSE.txt for details.

 org $fffc + ROM_START
 rorg $fffc
end_of_address_space 
 .word (start & $ffff)
 .word (start & $ffff)

 incbin "DpcPlusELF-post.arm"

    ; ARM Functions called via JSR
    SEG.U
    rorg $0000
pfsetup1 ds 1
pfsetup2 ds 1
pfsetup3 ds 1
pfsetup4 ds 1
pfsetup5 ds 1
pfsetup6 ds 1
pfsetup7 ds 1
pfsetup8 ds 1
pfsetup9 ds 1
pfsetup10 ds 1
pfsetup11 ds 1
pfsetup12 ds 1
pfsetup13 ds 1
pfsetup14 ds 1
pfsetup15 ds 1
pfsetup16 ds 1
pfsetup17 ds 1
pfsetup18 ds 1
pfsetup19 ds 1
pfsetup20 ds 1
pfsetup21 ds 1
pfsetup22 ds 1
pfsetup23 ds 1
pfsetup24 ds 1
pfsetup25 ds 1
pfsetup26 ds 1
pfsetup27 ds 1
pfsetup28 ds 1
pfsetup29 ds 1
pfsetup30 ds 1
pfsetup31 ds 1
pfsetup32 ds 1
