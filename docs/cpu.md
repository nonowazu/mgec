# Instructions

## LOAD

**Syntax**: `LOAD $R,$V`

Loads operand `$V` into a register `$R`.

**Related opcodes**

| Hex (Name) | Example     | Addressing Mode                 | Notes |
| :--------  | :---------- | :------------------------------ | :---- |
| $A0 (LDY)  | `LOAD Y,$V` | Immediate                       |       |
| $A1 (LDA)  | `LOAD A,$V` | Direct Indexed Indirect         |       |
| $A2 (LDX)  | `LOAD X,$V` | Immediate                       |       |
| $A3 (LDA)  | `LOAD A,$V` | Stack Relative                  |       |
| $A4 (LDY)  | `LOAD Y,$V` | Direct                          |       |
| $A5 (LDA)  | `LOAD A,$V` | Direct                          |       |
| $A6 (LDX)  | `LOAD X,$V` | Direct                          |       |
| $A7 (LDA)  | `LOAD A,$V` | Direct Indirect Long            |       |
| $A9 (LDA)  | `LOAD A,$V` | Immediate                       |       |
| $AC (LDY)  | `LOAD Y,$V` | Absolute                        |       |
| $AD (LDA)  | `LOAD A,$V` | Absolute                        |       |
| $AE (LDX)  | `LOAD X,$V` | Absolute                        |       |
| $AF (LDA)  | `LOAD A,$V` | Absolute Long                   |       |
| $B1 (LDA)  | `LOAD A,$V` | Direct Indirect Indexed         |       |
| $B2 (LDA)  | `LOAD A,$V` | Direct Indirect                 |       |
| $B3 (LDA)  | `LOAD A,$V` | Stack Relative Indirect Indexed |       |
| $B4 (LDY)  | `LOAD Y,$V` | Direct Indexed with X           |       |
| $B5 (LDA)  | `LOAD A,$V` | Direct Indexed with X           |       |
| $B6 (LDX)  | `LOAD X,$V` | Direct Indexed with Y           |       |
| $B7 (LDA)  | `LOAD A,$V` | Direct Indirect Long Indexed    |       |
| $B9 (LDA)  | `LOAD A,$V` | Absolute Indexed with Y         |       |
| $BC (LDY)  | `LOAD Y,$V` | Absolute Indexed with X         |       |
| $BD (LDA)  | `LOAD A,$V` | Absolute Indexed with X         |       |
| $BE (LDX)  | `LOAD X,$V` | Absolute Indexed with Y         |       |
| $BF (LDA)  | `LOAD A,$V` | Absolute Long Indexed with X    |       |

## TRANS

**Syntax**: `TRANS $R1,$R2`

Transfer the contents of `$R1` to `$R2`, overwriting the contents of $R2 in the process.

**Related Opcodes**

| Hex (Name) | Example     | Addressing Mode | Notes |
| :--------- | :---------- | :-------------- | :---- |
| $8A (TXA)  | `TRANS X,A` | Implied         |       |
| $98 (TYA)  | `TRANS Y,A` | Implied         |       |
| $9B (TXY)  | `TRANS X,Y` | Implied         |       |
| $AA (TAX)  | `TRANS A,X` | Implied         |       |
| $BB (TYX)  | `TRANS Y,X` | Implied         |       |


# Opcodes

|         |    **-0**    |    **-1**    |    **-2**    |    **-3**    |    **-4**    |    **-5**    |    **-6**    |    **-7**    |    **-8**     |    **-9**    |    **-A**     |    **-B**     |    **-C**    |    **-D**    |    **-E**    |    **-F**    |
| :-----: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :----------: | :-----------: | :----------: | :-----------: | :-----------: | :----------: | :----------: | :----------: | :----------: |
| **$0-** |     BRK      |     ORA      |     COP      |     ORA      |     TSB      |     ORA      |     ASL      |     ORA      |      PHP      |     ORA      |      ASL      |      PHD      |     TSB      |     ORA      |     ASL      |     ORA      |
| **$1-** |     BPL      |     ORA      |     ORA      |     ORA      |     TRB      |     ORA      |     ASL      |     ORA      |      CLC      |     ORA      |      INC      |      TCS      |     TRB      |     ORA      |     ASL      |     ORA      |
| **$2-** |     JSR      |     AND      |     JSL      |     AND      |     BIT      |     AND      |     ROL      |     AND      |      PLP      |     AND      |      ROL      |      PLD      |     BIT      |     AND      |     ROL      |     AND      |
| **$3-** |     BMI      |     AND      |     AND      |     AND      |     BIT      |     AND      |     ROL      |     AND      |      SEC      |     AND      |      DEC      |      TSC      |     BIT      |     AND      |     ROL      |     AND      |
| **$4-** |     RTI      |     EOR      |     WDM      |     EOR      |     MVP      |     EOR      |     LSR      |     EOR      |      PHA      |     EOR      |      LSR      |      PHK      |     JMP      |     EOR      |     LSR      |     EOR      |
| **$5-** |     BVC      |     EOR      |     EOR      |     EOR      |     MVN      |     EOR      |     LSR      |     EOR      |      CLI      |     EOR      |      PHY      |      TCD      |     JMP      |     EOR      |     LSR      |     EOR      |
| **$6-** |     RTS      |     ADC      |     PER      |     ADC      |     STZ      |     ADC      |     ROR      |     ADC      |      PLA      |     ADC      |      ROR      |      RTL      |     JMP      |     ADC      |     ROR      |     ADC      |
| **$7-** |     BVS      |     ADC      |     ADC      |     ADC      |     STZ      |     ADC      |     ROR      |     ADC      |      SEI      |     ADC      |      PLY      |      TDC      |     JMP      |     ADC      |     ROR      |     ADC      |
| **$8-** |     BRA      |     STA      |     BRL      |     STA      |     STY      |     STA      |     STX      |     STA      |      DEY      |     BIT      | [TXA](#trans) |      PHB      |     STY      |     STA      |     STX      |     STA      |
| **$9-** |     BCC      |     STA      |     STA      |     STA      |     STY      |     STA      |     STX      |     STA      | [TYA](#trans) |     STA      |      TXS      | [TXY](#trans) |     STZ      |     STA      |     STZ      |     STA      |
| **$A-** | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) | [TAY](#trans) | [LDA](#load) | [TAX](#trans) |      PLB      | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) |
| **$B-** |     BCS      | [LDA](#load) | [LDA](#load) | [LDA](#load) | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) |      CLV      | [LDA](#load) |      TSX      | [TYX](#trans) | [LDY](#load) | [LDA](#load) | [LDX](#load) | [LDA](#load) |
| **$C-** |     CPY      |     CMP      |     REP      |     CMP      |     CPY      |     CMP      |     DEC      |     CMP      |      INY      |     CMP      |      DEX      |      WAI      |     CPY      |     CMP      |     DEC      |     CMP      |
| **$D-** |     BNE      |     CMP      |     CMP      |     CMP      |     PEI      |     CMP      |     DEC      |     CMP      |      CLD      |     CMP      |      PHX      |      STP      |     JML      |     CMP      |     DEC      |     CMP      |
| **$E-** |     CPX      |     SBC      |     SEP      |     SBC      |     CPX      |     SBC      |     INC      |     SBC      |      INX      |     SBC      |      NOP      |      XBA      |     CPX      |     SBC      |     INC      |     SBC      |
| **$F-** |     BEQ      |     SBC      |     SBC      |     SBC      |     PEA      |     SBC      |     INC      |     SBC      |      SED      |     SBC      |      PLX      |      XCE      |     JSR      |     SBC      |     INC      |     SBC      |
