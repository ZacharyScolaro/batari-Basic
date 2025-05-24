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


    ; Store the addresses as uint16[] for the elf driver to use
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

     ORG $0800 + ROM_START
     RORG $0800

    ; c: Playfield Colors Control
    ;   0: Playfield Colors has its own PF_FRAC_INC, PF_WRITE_OFFSET, and PF_VER_SCROLL
    ;   1: fov settings are applied to playfield colors
    ;
    ; b: Background Colors Control
    ;   0: Background Colors has its own PF_FRAC_INC, PF_WRITE_OFFSET, and PF_VER_SCROLL
    ;   1: fov settings are applied to background colors
    ;
    ; f: Fractional Increment Control
    ;   0: Each playfield column has its own PF_FRAC_INC
    ;   1: PF_FRAC_INC_0 is applied to all columns
    ;
    ; o: Write Offset Control
    ;   0: Each playfield column has its own PF_WRITE_OFFSET
    ;   1: PF_WRITE_OFFSET_0 is applied to all columns
    ;
    ; v: Vertical Scroll Control
    ;   0: Each playfield column has its own PF_VER_SCROLL
    ;   1: PF_VER_SCROLL_0 is applied to all columns
    ;
    ; p: PFSCROLL mode
    ;   0: Scroll resolution matches FRACINC registers and pfscroll changes write offsets,
    ;   1-Fine grain. -128 to +127 scanlines
    ;
    ; ww: PF width. How many PF columns wide to scroll through horizontally. Each PF column is 8 PF pixels wide (32 pixels)
    ;   0: 4 columns with sides set to PF0. No horizontal scrolling. Primarily for backwards compatability with DPC+ kernel.
    ;   1: 5 columns. 160 (40 PF) Pixels wide. 
    ;   2: 10 columns. 320 (80 PF) Pixels wide.
    ;   3: 15 columns. 480 (120 PF) Pixels wide.
PF_MODE ; cbfo vpww
    .byte $00

    ; 0-31 Which playfield column write operations will start with 
    ; when writing multiple columns the operation will wrap back to column 0 after column 31
PF_WRITE_INDEX 
    .byte $00

    ; Horizontal scroll position in pixels. I.E. 16 would move Playfield 4 PF pixels left.
PF_HOR_SCROLL_LO
    .byte $00
PF_HOR_SCROLL_HI
    .byte $00

PF_FRAC_INC
PF_FRAC_INC_0
    .byte 00
PF_WRITE_OFFSET ; 0-255 where to start writing in each 256 byte column buffer. Writing past the end will wrap back to 0 automatically
PF_WRITE_OFFSET_0
    .byte $00
PF_VER_SCROLL_LO
PF_VER_SCROLL_LO_0
    .byte $00
PF_VER_SCROLL_HI
PF_VER_SCROLL_HI_0
    .byte $00

PF_FRAC_INC_1
    .byte 00
PF_WRITE_OFFSET_1
    .byte $00
PF_VER_SCROLL_LO_1
    .byte $00
PF_VER_SCROLL_HI_1
    .byte $00

PF_FRAC_INC_2
    .byte 00
PF_WRITE_OFFSET_2
    .byte $00
PF_VER_SCROLL_LO_2
    .byte $00
PF_VER_SCROLL_HI_2
    .byte $00

PF_FRAC_INC_3
    .byte 00
PF_WRITE_OFFSET_3
    .byte $00
PF_VER_SCROLL_LO_3
    .byte $00
PF_VER_SCROLL_HI_3
    .byte $00

PF_FRAC_INC_4
    .byte 00
PF_WRITE_OFFSET_4
    .byte $00
PF_VER_SCROLL_LO_4
    .byte $00
PF_VER_SCROLL_HI_4
    .byte $00

PF_FRAC_INC_5
    .byte 00
PF_WRITE_OFFSET_5
    .byte $00
PF_VER_SCROLL_LO_5
    .byte $00
PF_VER_SCROLL_HI_5
    .byte $00

PF_FRAC_INC_6
    .byte 00
PF_WRITE_OFFSET_6
    .byte $00
PF_VER_SCROLL_LO_6
    .byte $00
PF_VER_SCROLL_HI_6
    .byte $00

PF_FRAC_INC_7
    .byte 00
PF_WRITE_OFFSET_7
    .byte $00
PF_VER_SCROLL_LO_7
    .byte $00
PF_VER_SCROLL_HI_7
    .byte $00

PF_FRAC_INC_8
    .byte 00
PF_WRITE_OFFSET_8
    .byte $00
PF_VER_SCROLL_LO_8
    .byte $00
PF_VER_SCROLL_HI_8
    .byte $00

PF_FRAC_INC_9
    .byte 00
PF_WRITE_OFFSET_9
    .byte $00
PF_VER_SCROLL_LO_9
    .byte $00
PF_VER_SCROLL_HI_9
    .byte $00

PF_FRAC_INC_10
    .byte 00
PF_WRITE_OFFSET_10
    .byte $00
PF_VER_SCROLL_LO_10
    .byte $00
PF_VER_SCROLL_HI_10
    .byte $00

PF_FRAC_INC_11
    .byte 00
PF_WRITE_OFFSET_11
    .byte $00
PF_VER_SCROLL_LO_11
    .byte $00
PF_VER_SCROLL_HI_11
    .byte $00

PF_FRAC_INC_12
    .byte 00
PF_WRITE_OFFSET_12
    .byte $00
PF_VER_SCROLL_LO_12
    .byte $00
PF_VER_SCROLL_HI_12
    .byte $00

PF_FRAC_INC_13
    .byte 00
PF_WRITE_OFFSET_13
    .byte $00
PF_VER_SCROLL_LO_13
    .byte $00
PF_VER_SCROLL_HI_13
    .byte $00

PF_FRAC_INC_14
    .byte 00
PF_WRITE_OFFSET_14
    .byte $00
PF_VER_SCROLL_LO_14
    .byte $00
PF_VER_SCROLL_HI_14
    .byte $00

PF_FRAC_INC_PFCOL
    .byte 00
PF_WRITE_OFFSET_PFCOL
    .byte $00
PF_VER_SCROLL_LO_PFCOL
    .byte $00
PF_VER_SCROLL_HI_PFCOL
    .byte $00

PF_FRAC_INC_BKCOL
    .byte 00
PF_WRITE_OFFSET_BKCOL
    .byte $00
PF_VER_SCROLL_LO_BKCOL
    .byte $00
PF_VER_SCROLL_HI_BKCOL
    .byte $00

     ORG $1080 + ROM_START
     RORG $1080

