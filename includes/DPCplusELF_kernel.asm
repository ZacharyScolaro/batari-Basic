drawscreen
     nop
end_drawscreen
     rts

pfsetup     
     
     sty temp1 
     sta temp2
     stx temp3
     ldx #3
pfsetupp
     lda dffraclow,x
     sta DF0LOW,x
     lda dffrachi,x
     sta DF0HI,x 
     lda temp2
     sta PARAMETER
     lda temp3
     sta PARAMETER
     stx PARAMETER
     sty PARAMETER 
     LDA #1
     sta CALLFUNCTION
     clc
     lda temp2
     adc temp1
     sta temp2
     lda temp3
     adc #0
     sta temp3
     dex
     bpl pfsetupp
     RETURN


fetcher_address_table
dflow     
     .byte <P0COLOR
     .byte <P1COLOR
     .byte <P0GFX
     .byte <P1GFX
     .byte <P1SKIP
     .byte <JUMPTABLELO
     .byte <JUMPTABLEHI
     .byte <USERSTACK
dfhigh
     .byte (>P0COLOR)
     .byte (>P1COLOR)
     .byte (>P0GFX)
     .byte (>P1GFX)
     .byte (>P1SKIP)
     .byte (>JUMPTABLELO)
     .byte (>JUMPTABLEHI)
     .byte (>USERSTACK)
dffraclow
     .byte <PF1L
     .byte <PF2L
     .byte <PF1R
     .byte <PF2R
     .byte <PFCOLS
     .byte <NUSIZREFP
     .byte <BKCOLS
     .byte <P1HMP
dffrachi
     .byte (>PF1L)
     .byte (>PF2L)
     .byte (>PF1R)
     .byte (>PF2R)
     .byte (>PFCOLS)
     .byte (>NUSIZREFP) 
     .byte (>BKCOLS)
     .byte (>P1HMP)
