# Instructions

## LOAD

Loads an operand into a register


# Opcodes

|         |    **-0**    |    **-1**    |    **-2**    |    **-3**    |    **-4**    |    **-5**    |    **-6**    |    **-7**    | **-8** |    **-9**    | **-A** | **-B** |    **-C**    |    **-D**    |    **-E**    |    **-F**    |
| :-----: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----: | :----------: | :----: | :----: | :----------: | :----------: | :----------: | :----------: |
| **$0-** |     BRK      |     ORA      |     COP      |     ORA      |     TSB      |     ORA      |     ASL      |     ORA      |  PHP   |     ORA      |  ASL   |  PHD   |     TSB      |     ORA      |     ASL      |     ORA      |
| **$1-** |     BPL      |     ORA      |     ORA      |     ORA      |     TRB      |     ORA      |     ASL      |     ORA      |  CLC   |     ORA      |  INC   |  TCS   |     TRB      |     ORA      |     ASL      |     ORA      |
| **$2-** |     JSR      |     AND      |     JSL      |     AND      |     BIT      |     AND      |     ROL      |     AND      |  PLP   |     AND      |  ROL   |  PLD   |     BIT      |     AND      |     ROL      |     AND      |
| **$3-** |     BMI      |     AND      |     AND      |     AND      |     BIT      |     AND      |     ROL      |     AND      |  SEC   |     AND      |  DEC   |  TSC   |     BIT      |     AND      |     ROL      |     AND      |
| **$4-** |     RTI      |     EOR      |     WDM      |     EOR      |     MVP      |     EOR      |     LSR      |     EOR      |  PHA   |     EOR      |  LSR   |  PHK   |     JMP      |     EOR      |     LSR      |     EOR      |
| **$5-** |     BVC      |     EOR      |     EOR      |     EOR      |     MVN      |     EOR      |     LSR      |     EOR      |  CLI   |     EOR      |  PHY   |  TCD   |     JMP      |     EOR      |     LSR      |     EOR      |
| **$6-** |     RTS      |     ADC      |     PER      |     ADC      |     STZ      |     ADC      |     ROR      |     ADC      |  PLA   |     ADC      |  ROR   |  RTL   |     JMP      |     ADC      |     ROR      |     ADC      |
| **$7-** |     BVS      |     ADC      |     ADC      |     ADC      |     STZ      |     ADC      |     ROR      |     ADC      |  SEI   |     ADC      |  PLY   |  TDC   |     JMP      |     ADC      |     ROR      |     ADC      |
| **$8-** |     BRA      |     STA      |     BRL      |     STA      |     STY      |     STA      |     STX      |     STA      |  DEY   |     BIT      |  TXA   |  PHB   |     STY      |     STA      |     STX      |     STA      |
| **$9-** |     BCC      |     STA      |     STA      |     STA      |     STY      |     STA      |     STX      |     STA      |  TYA   |     STA      |  TXS   |  TXY   |     STZ      |     STA      |     STZ      |     STA      |
| **$A-** | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) |  TAY   | [LDA](#load) |  TAX   |  PLB   | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) |
| **$B-** |     BCS      | [LDA](#load) | [LDA](#load) | [LDA](#load) | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) |  CLV   | [LDA](#load) |  TSX   |  TYX   | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) |
| **$C-** |     CPY      |     CMP      |     REP      |     CMP      |     CPY      |     CMP      |     DEC      |     CMP      |  INY   |     CMP      |  DEX   |  WAI   |     CPY      |     CMP      |     DEC      |     CMP      |
| **$D-** |     BNE      |     CMP      |     CMP      |     CMP      |     PEI      |     CMP      |     DEC      |     CMP      |  CLD   |     CMP      |  PHX   |  STP   |     JML      |     CMP      |     DEC      |     CMP      |
| **$E-** |     CPX      |     SBC      |     SEP      |     SBC      |     CPX      |     SBC      |     INC      |     SBC      |  INX   |     SBC      |  NOP   |  XBA   |     CPX      |     SBC      |     INC      |     SBC      |
| **$F-** |     BEQ      |     SBC      |     SBC      |     SBC      |     PEA      |     SBC      |     INC      |     SBC      |  SED   |     SBC      |  PLX   |  XCE   |     JSR      |     SBC      |     INC      |     SBC      |