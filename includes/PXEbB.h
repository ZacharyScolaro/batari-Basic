; Provided under the CC0 license. See the included LICENSE.txt for details.

  SEG.U PER_KERNEL_VARS
  ORG $0000

; Variables that get multiple copies for multiple kernels

PF_HOR_SCROLL_LO ds 1
PF_HOR_SCROLL_HI ds 1

PF_FRAC_INC
PF_FRAC_INC_0 ds 1
PF_WRITE_OFFSET
PF_WRITE_OFFSET_0 ds 1
PF_VER_SCROLL_LO
PF_VER_SCROLL_LO_0 ds 1
PF_VER_SCROLL_HI
PF_VER_SCROLL_HI_0 ds 1

PF_FRAC_INC_1 ds 1
PF_WRITE_OFFSET_1 ds 1
PF_VER_SCROLL_LO_1 ds 1
PF_VER_SCROLL_HI_1 ds 1

PF_FRAC_INC_2 ds 1
PF_WRITE_OFFSET_2 ds 1
PF_VER_SCROLL_LO_2 ds 1
PF_VER_SCROLL_HI_2 ds 1

PF_FRAC_INC_3 ds 1
PF_WRITE_OFFSET_3 ds 1
PF_VER_SCROLL_LO_3 ds 1
PF_VER_SCROLL_HI_3 ds 1

PF_FRAC_INC_4 ds 1
PF_WRITE_OFFSET_4 ds 1
PF_VER_SCROLL_LO_4 ds 1
PF_VER_SCROLL_HI_4 ds 1

PF_FRAC_INC_5 ds 1
PF_WRITE_OFFSET_5 ds 1
PF_VER_SCROLL_LO_5 ds 1
PF_VER_SCROLL_HI_5 ds 1

PF_FRAC_INC_6 ds 1
PF_WRITE_OFFSET_6 ds 1
PF_VER_SCROLL_LO_6 ds 1
PF_VER_SCROLL_HI_6 ds 1

PF_FRAC_INC_7 ds 1
PF_WRITE_OFFSET_7 ds 1
PF_VER_SCROLL_LO_7 ds 1
PF_VER_SCROLL_HI_7 ds 1

PF_FRAC_INC_8 ds 1
PF_WRITE_OFFSET_8 ds 1
PF_VER_SCROLL_LO_8 ds 1
PF_VER_SCROLL_HI_8 ds 1

PF_FRAC_INC_9 ds 1
PF_WRITE_OFFSET_9 ds 1
PF_VER_SCROLL_LO_9 ds 1
PF_VER_SCROLL_HI_9 ds 1

PF_FRAC_INC_10 ds 1
PF_WRITE_OFFSET_10 ds 1
PF_VER_SCROLL_LO_10 ds 1
PF_VER_SCROLL_HI_10 ds 1

PF_FRAC_INC_11 ds 1
PF_WRITE_OFFSET_11 ds 1
PF_VER_SCROLL_LO_11 ds 1
PF_VER_SCROLL_HI_11 ds 1

PF_FRAC_INC_12 ds 1
PF_WRITE_OFFSET_12 ds 1
PF_VER_SCROLL_LO_12 ds 1
PF_VER_SCROLL_HI_12 ds 1

PF_FRAC_INC_13 ds 1
PF_WRITE_OFFSET_13 ds 1
PF_VER_SCROLL_LO_13 ds 1
PF_VER_SCROLL_HI_13 ds 1

PF_FRAC_INC_14 ds 1
PF_WRITE_OFFSET_14 ds 1
PF_VER_SCROLL_LO_14 ds 1
PF_VER_SCROLL_HI_14 ds 1

PF_FRAC_INC_PFCOL ds 1
PF_WRITE_OFFSET_PFCOL ds 1
PF_VER_SCROLL_LO_PFCOL ds 1
PF_VER_SCROLL_HI_PFCOL ds 1

PF_FRAC_INC_BKCOL ds 1
PF_WRITE_OFFSET_BKCOL ds 1
PF_VER_SCROLL_LO_BKCOL ds 1
PF_VER_SCROLL_HI_BKCOL ds 1

scorecolor ds 1
score ds 3
COLUM0 ds 1
COLUM1 ds 1
COLUBL ds 1
HMM0 ds 1
HMM1 ds 1
HMBL ds 1
player0pointerlo ds 1
player0pointerhi ds 1

missile0x ds 1
missile1x ds 1
ballx ds 1
player0color
player0colorlo ds 1
player0colorhi ds 1

missile0y ds 1
missile1y ds 1
bally ds 1

missile0height ds 1
missile1height ds 1
ballheight ds 1

statusbarlength ds 1 ; needed?

lifecolor ds 1
pfscorecolor = lifecolor
aux4 ds 1

lifepointer ds 1
lives ds 1
pfscore1 = lifepointer
pfscore2 = lives

; Player Variables
player0x ds 1
player0y ds 1
NUSIZ0 ds 1
REFP0 ds 1


; Variables for Sprites mode
SPRITE_0 ds 1
CEL_0 ds 1
INK_0 ds 1
CEL_TOP_OFFSET_0 ds 1
CEL_BOT_OFFSET_0
player0height ds 1

PF0 ds 1  ; for backwards compatibility

; PF vars that get a copy per kernel
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
    ;   2: 8 columns. 256 (64 PF) Pixels wide.
    ;   3: 15 columns. 480 (120 PF) Pixels wide.
PF_MODE ds 1 ; cbfo vpww
    ; Horizontal scroll position in pixels. I.E. 16 would move Playfield 4 PF pixels left.

    ; 0-14 Which playfield column write operations will start with 
    ; when writing multiple columns the operation will wrap back to column 0 after column 14
PF_WRITE_INDEX 
    .byte $00

  SEG.U TIA_REGISTERS_WRITE
  ORG $0070


CTRLPF      ds 1    ; $70    
AUDC0       ds 1    ; $71   0000 xxxx   Audio Control 0
AUDC1       ds 1    ; $72   0000 xxxx   Audio Control 1
AUDF0       ds 1    ; $73   000x xxxx   Audio Frequency 0
AUDF1       ds 1    ; $74   000x xxxx   Audio Frequency 1
AUDV0       ds 1    ; $75   0000 xxxx   Audio Volume 0
AUDV1       ds 1    ; $76   0000 xxxx   Audio Volume 1
SWCHA       ds 1    ; $77      Port A data register for joysticks: Bits 4-7 for player 1.  Bits 0-3 for player 2.
SWCHA2		ds 1	; $78		Used by PXE for Quadtari support
SWACNT      ds 1    ; $79      Port A data direction register (DDR)
SWCHB       ds 1    ; $7a		Port B data (console switches)
SWBCNT      ds 1    ; $7b      Port B DDR
; Used by PXE to make "on JOYx_DIR gosub" faster and smaller
JOY0_DIR	ds 1	; $7C
JOY1_DIR	ds 1	; $7D
JOY2_DIR	ds 1	; $7E
JOY3_DIR	ds 1	; $7F

;-------------------------------------------------------------------------------

  SEG.U TIA_REGISTERS_READ
  ORG $0080

;											bit 7   bit 6
CXM0P       ds 1    ; $70       xx00 0000       Read Collision  M0-P1   M0-P0
CXM1P       ds 1    ; $71       xx00 0000                       M1-P0   M1-P1
CXP0FB      ds 1    ; $72       xx00 0000                       P0-PF   P0-BL
CXP1FB      ds 1    ; $73       xx00 0000                       P1-PF   P1-BL
CXM0FB      ds 1    ; $74       xx00 0000                       M0-PF   M0-BL
CXM1FB      ds 1    ; $75       xx00 0000                       M1-PF   M1-BL
CXBLPF      ds 1    ; $76       x000 0000                       BL-PF   -----
CXPPMM      ds 1    ; $77       xx00 0000                       P0-P1   M0-M1
INPT0       ds 1    ; $78       x000 0000       Read Pot Port 0
INPT1       ds 1    ; $79       x000 0000       Read Pot Port 1
INPT2       ds 1    ; $7A       x000 0000       Read Pot Port 2
INPT3       ds 1    ; $7B       x000 0000       Read Pot Port 3
INPT4       ds 1    ; $7C		x000 0000       Read Input (Trigger) 0
INPT5       ds 1	; $7D		x000 0000       Read Input (Trigger) 1
INPT6       ds 1    ; $7E		x000 0000       Read Input (Trigger) 2
INPT7       ds 1	; $7F		x000 0000       Read Input (Trigger) 3

 SEG.U SHARED_VARS
 org $0090

temp1 ds 1
temp2 ds 1
temp3 ds 1
temp4 ds 1
temp5 ds 1
temp6 ds 1
temp7 ds 1

A ds 1
a = A
B ds 1
b = B
C ds 1
c = C
D ds 1
d = D
E ds 1
e = E
F ds 1
f = F
G ds 1
g = G
H ds 1
h = H
I ds 1
i = I
J ds 1
j = J
K ds 1
k = K
L ds 1
l = L
M ds 1
m = M
N ds 1
n = N
O ds 1
o = O
P ds 1
p = P
Q ds 1
q = Q
R ds 1
r = R
S ds 1
s = S
T ds 1
t = T
U ds 1
u = U
V ds 1
v = V
W ds 1
w = W
X ds 1
x = X
Y ds 1
y = Y
Z ds 1
z = Z

var0 ds 1
var1 ds 1
var2 ds 1
var3 ds 1
var4 ds 1
var5 ds 1
var6 ds 1
var7 ds 1
var8 ds 1
var9 ds 1
var10 ds 1
var11 ds 1
var12 ds 1
var13 ds 1
var14 ds 1
var15 ds 1
var16 ds 1
var17 ds 1
var18 ds 1
var19 ds 1
var20 ds 1
var21 ds 1
var22 ds 1
var23 ds 1
var24 ds 1
var25 ds 1
var26 ds 1
var27 ds 1
var28 ds 1
var29 ds 1
var30 ds 1
var31 ds 1
var32 ds 1
var33 ds 1
var34 ds 1
var35 ds 1
var36 ds 1
var37 ds 1
var38 ds 1
var39 ds 1
var40 ds 1
var41 ds 1
var42 ds 1
var43 ds 1
var44 ds 1
var45 ds 1
var46 ds 1
var47 ds 1
var48 ds 1
var49 ds 1
var50 ds 1
var51 ds 1
var52 ds 1
var53 ds 1
var54 ds 1
var55 ds 1
var56 ds 1
var57 ds 1
var58 ds 1
var59 ds 1
var60 ds 1
var61 ds 1
var62 ds 1
var63 ds 1
var64 ds 1
var65 ds 1
var66 ds 1
var67 ds 1
var68 ds 1
var69 ds 1
var70 ds 1
var71 ds 1
var72 ds 1
var73 ds 1
var74 ds 1
var75 ds 1
var76 ds 1
var77 ds 1
var78 ds 1
var79 ds 1
var80 ds 1
var81 ds 1
var82 ds 1
var83 ds 1
var84 ds 1
var85 ds 1
var86 ds 1
var87 ds 1
var88 ds 1
var89 ds 1
var90 ds 1
var91 ds 1
var92 ds 1
var93 ds 1
var94 ds 1
var95 ds 1
var96 ds 1
var97 ds 1
var98 ds 1
var99 ds 1

player1x ds 1
player2x ds 1
player3x ds 1
player4x ds 1
player5x ds 1
player6x ds 1
player7x ds 1
player8x ds 1
player9x ds 1
player10x ds 1
player11x ds 1
player12x ds 1
player13x ds 1
player14x ds 1
player15x ds 1
player16x ds 1

player1y ds 1
player2y ds 1
player3y ds 1
player4y ds 1
player5y ds 1
player6y ds 1
player7y ds 1
player8y ds 1
player9y ds 1
player10y ds 1
player11y ds 1
player12y ds 1
player13y ds 1
player14y ds 1
player15y ds 1
player16y ds 1


_NUSIZ1
NUSIZ1 ds 1
NUSIZ2 ds 1
NUSIZ3 ds 1
NUSIZ4 ds 1
NUSIZ5 ds 1
NUSIZ6 ds 1
NUSIZ7 ds 1
NUSIZ8 ds 1
NUSIZ9 ds 1
NUSIZ10 ds 1
NUSIZ11 ds 1
NUSIZ12 ds 1
NUSIZ13 ds 1
NUSIZ14 ds 1
NUSIZ15 ds 1
NUSIZ16 ds 1

SPRITE_1 ds 16
CEL_1 ds 16
INK_1 ds 16
CEL_TOP_OFFSET_1 ds 16
CEL_BOT_OFFSET_1
player1height ds 1
player2height ds 1
player3height ds 1
player4height ds 1
player5height ds 1
player6height ds 1
player7height ds 1
player8height ds 1
player9height ds 1
player10height ds 1
player11height ds 1
player12height ds 1
player13height ds 1
player14height ds 1
player15height ds 1
player16height ds 1

; Graphics modes
GFX_MODE
simple48 .byte 0 ; 0-Normal Multisprite kernel lines 0-179, 1-48 Pixel Sprite using backgroundcolor, playfieldcolor, and playfield data
                 ; 1 - 48 pixel sprite mode
                 ; 2 - no score shown at bottom. top kernel fills all 188 lines
                 ; 4 - Sprite Cel Ink mode
                 
; PaddleRange set to 0 to disable, paddle value will be converted into a number between 0 and range inclusive.
PaddleRange0:
    .byte 00
PaddleRange1:
    .byte 00
PaddleRange2:
    .byte 00
PaddleRange3:
    .byte 00


 echo "Available Stack ram:",($200-*)d

 SEG.U vars
 org $0200
 
 ; allocate additional vars here as needed
 
 echo "free extended ram:",($e00-*)d


 MAC RETURN	; no bank switching needed
     rts
 ENDM
 seg
rand = RANDOM0NEXT
KERNEL_LINES = 178*76/64 ; warning: not all values will work
OVERSCAN_LINES = 128+33*76/64 ; again, not all values work
C_function = 0
CcodeData = C_function + 4
playerpointers = CcodeData + 64
P1GFX = playerpointers + 64
P1COLOR = P1GFX + 256
P0GFX = P1COLOR + 256
P0COLOR = P0GFX + 256
PF1L = P0COLOR + 256
PF2L = PF1L + 256
PF1R = PF2L + 256
PF2R = PF1R + 512 ; Avoid Palette collision
PFCOLS = PF2R + 0
JUMPTABLELO = PFCOLS + 256
JUMPTABLEHI = JUMPTABLELO + 12
P1HMP = JUMPTABLEHI + 12
P1SKIP = P1HMP + 13
NUSIZREFP = P1SKIP + 12
scoredata = NUSIZREFP + 12
BKCOLS = scoredata + 96
STACKbegin = BKCOLS + 256
USERSTACK = STACKbegin + 256 ; stack starts here and goes down!!!!
