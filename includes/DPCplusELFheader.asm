; Provided under the CC0 license. See the included LICENSE.txt for details.

 processor 6502

 include "vcs.h"
 include "macro.h"
 include "DPCplus.h"
 include "DPCplusELFbB.h"
 include "2600basic_variable_redefs.h"

     ORG $0000
 incbin "DpcPlusELF-pre.arm"

ROM_START = .

     ORG $0000 + ROM_START
     RORG $0000
     dc "DPC+ELF"

     ORG $0100 + ROM_START
     RORG $0100






    .byte <drawscreen
    .byte >drawscreen
    .byte <end_drawscreen
    .byte >end_drawscreen
    .byte <BKCOLS
    .byte >BKCOLS
    .byte <PFCOLS
    .byte >PFCOLS
    .byte <C_function
    .byte >C_function
    .byte <player0x
    .byte >player0x
    .byte <player0y
    .byte >player0y
    .byte <player0color
    .byte >player0color
    .byte <player0height
    .byte >player0height
    .byte <player0pointerhi
    .byte >player0pointerhi
    .byte <player0pointerlo
    .byte >player0pointerlo
    .byte <playerpointers
    .byte >playerpointers
    .byte <player1x
    .byte >player1x
    .byte <player1y
    .byte >player1y
    .byte <player1height
    .byte >player1height
    .byte <_NUSIZ1
    .byte >_NUSIZ1
    .byte <COLUM0
    .byte >COLUM0
    .byte <missile0x
    .byte >missile0x
    .byte <missile0y
    .byte >missile0y
    .byte <missile0height
    .byte >missile0height
    .byte <COLUM1
    .byte >COLUM1
    .byte <missile1x
    .byte >missile1x
    .byte <missile1y
    .byte >missile1y
    .byte <missile1height
    .byte >missile1height
    .byte <COLUBL
    .byte >COLUBL
    .byte <ballx
    .byte >ballx
    .byte <bally
    .byte >bally
    .byte <ballheight
    .byte >ballheight
    .byte <pfscorecolor
    .byte >pfscorecolor
    .byte <scoredata
    .byte >scoredata
    .byte <scoretable
    .byte >scoretable
    .byte <score
    .byte >score
    .byte <pfscore1
    .byte >pfscore1
    .byte <pfscore2
    .byte >pfscore2
    .byte <PF1L
    .byte >PF1L

     ORG $1080 + ROM_START
     RORG $1080

