; Provided under the CC0 license. See the included LICENSE.txt for details.

 org $fffc + ROM_START
 rorg $fffc
end_of_address_space 
 .word (start & $ffff)
 .word (start & $ffff)

 incbin "DpcPlusELF-post.arm"
