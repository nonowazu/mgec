# Addressing Modes

## Absolute
Mnemonic: `a`

The next two bytes of the instruction are the 16 low-order bits of the effective address. The Data Bank register contains the 8 high-order bits of the effective address.
|              |   |                    |              |              |
| :----------- | - | :----------------- | :----------- | :----------- |
| Instruction: |   | Opcode             | Address Low  | Address High |
| Operand:     |   | Data Bank Register | Address High | Address Low  |

## Absolute Indexed Indirect
Mnemonic: `(a,x)`

The next two bytes of the instruction are added to the X register contents to form a pointer in bank 0. The contents of the pointer are then used as the 16 low-order bits of the effective address. 

|              |   |                       |                         |                      |
| :----------- | - | :-------------------- | :---------------------- | :------------------- |
| Instruction: |   | Opcode                | Address Low             | Address High         |
|              |   |                       | Address High            | Address Low          |
|              | + |                       | \[X Register High\]     | X Register Low       |
| Pointer:     | = | `0x00`                | Pointer Address High    | Pointer Address Low  |
| Operand:     |   | Program Bank Register | Dereferenced Address +1 | Dereferenced Address |

## Absolute Indexed with X
Mnemonic: `a,x`

The next two bytes of the instruction are added to the X register contents to form the 16 low-order bits of the effective address. The Data Bank register contains the 8 high-order bits of the effective address.

|              |   |                              |                             |                            |
| :----------- | - | :--------------------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode                       | Address Low                 | Address High               |
|              |   | Data Bank Register           | Address High                | Address Low                |
|              | + |                              | \[X Register High\]         | X Register Low             |
| Operand:     | = | Effective Address bits 23-16 | Effective Address bits 15-8 | Effective Address bits 7-0 |

## Absolute Indexed with Y
Mnemonic: `a,y`

The next two bytes of the instruction are added to the Y register contents to form the 16 low-order bits of the effective address. The Data Bank register contains the 8 high-order bits of the effective address.

|              |   |                              |                             |                            |
| :----------- | - | :--------------------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode                       | Address Low                 | Address High               |
|              |   | Data Bank Register           | Address High                | Address Low                |
|              | + |                              | \[Y Register High\]         | Y Register Low             |
| Operand:     | = | Effective Address bits 23-16 | Effective Address bits 15-8 | Effective Address bits 7-0 |

## Absolute Indirect
Mnemonic: `(a)`

The next two bytes of the instruction form a pointer to an address in bank 0. This address is the operand. With the Jump Long (JML) instruction, the address is 24 bits wide, otherwise it is 16 bits wide.

|              |   |                             |                         |                      |
| :----------- | - | :-------------------------- | :---------------------- | :------------------- |
| Instruction: |   | Opcode                      | Address Low             | Address High         |
| Pointer:     |   | `0x00`                      | Address High            | Address Low          |
| Operand:     |   | \[Dereferenced Address +2\] | Dereferenced Address +1 | Dereferenced Address |

## Absolute Long Indexed with X
Mnemonic: `al,x`

The next three bytes of the instruction are added to the X register contents. This forms the 24-bit effective address. 

|              |   |        |                              |                             |                            |
| :----------- | - | :----- | :--------------------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode | Address Low                  | Address High                | Bank Address               |
|              |   |        | Bank Address                 | Address High                | Address Low                |
|              | + |        |                              | \[X Register High\]         | X Register Low             |
| Operand:     | = |        | Effective Address bits 23-16 | Effective Address bits 15-8 | Effective Address bits 7-0 |

## Absolute Long
Mnemonic: `al`

The next three bytes of the instruction form the 24-bit effective address.

|              |   |        |              |              |              |
| :----------- | - | :----- | :----------- | :------------| :----------- |
| Instruction: |   | Opcode | Address Low  | Address High | Bank Address |
| Operand:     |   |        | Bank Address | Address High | Address Low  |

## Accumulator
Mnemonic: `A`

The operand is not found in the next few bytes of instructions, but is the accumulator.

## Block Move
Mnemonic: `xyc`

The second byte of the instruction is the destination bank. The third byte of the instruction is the source bank. The Y register contains the 16 low bits of the destination address, and the X register contains the 16 low bits of the source address. The accumulator contains one less than the number of bytes to move.

|                      |   |                  |                     |                |
| :------------------- | - | :--------------- | :------------------ | :------------- |
| Instruction:         |   | Opcode           | Destination Bank    | Source Bank    |
| Source Address:      |   | Source Bank      | \[X Register High\] | X Register Low |
| Destination Address: |   | Destination Bank | \[Y Register High\] | Y Register Low |

## Direct Indexed Indirect
Mnemonic: `(d,x)`

The second byte of the instruction is added to the sum of the Direct Page register and the X register. The result is a pointer to the 16 low bits of the effective address. The Data Bank register contains the 8 high bits of the effective address.

|              |   |                              |                             |                            |
| :----------- | - | :--------------------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode                       | Offset                      |                            |
|              |   |                              | Direct Register High        | Direct Address Low         |
|              | + |                              |                             | Offset                     |
|              | + |                              | \[X Register High\]         | X Register Low             |
| Pointer:     | = | `0x00`                       | Pointer Address High        | Pointer Address Low        |
|              |   |                              | Dereferenced Address +1     | Dereferenced Address       |
|              | + | Data Bank Register           | `0x00`                      | `0x00`                     |
| Operand:     | = | Effective Address bits 23-16 | Effective Address bits 15-8 | Effective Address bits 7-0 |

## Direct Indexed with X

Mnemonic: `d,x`

The second byte of the instruction is added to the sum of the Direct Page Register and the X register. This forms the effective 16-bit address in Bank 0.

|              |   |        |                        |                       |
| :----------- | - | :----- | :--------------------- | :-------------------- |
| Instruction: |   | Opcode | Offset                 |                       |
|              |   |        | Direct Register High   | Direct Address Low    |
|              | + |        |                        | Offset                |
|              | + |        | \[X Register High\]    | X Register Low        |
| Operand:     | = | `0x00` | Effective Address High | Effective Address Low |

## Direct Indexed with Y

Mnemonic: `d,y`

The second byte of the instruction is added to the sum of the Direct Page Register and the Y register. This forms the effective 16-bit address in Bank 0.

|              |   |        |                        |                       |
| :----------- | - | :----- | :--------------------- | :-------------------- |
| Instruction: |   | Opcode | Offset                 |                       |
|              |   |        | Direct Register High   | Direct Address Low    |
|              | + |        |                        | Offset                |
|              | + |        | \[Y Register High\]    | Y Register Low        |
| Operand:     | = | `0x00` | Effective Address High | Effective Address Low |

## Direct Indirect Indexed

Mnemonic: `(d),y`

The second byte of the instruction is added to the Direct Page register. This forms a pointer in Bank 0 to the 16 low-order bits of the base address. The Data Bank Register contains the 8 high-order bits of the base address. The Y register is then added to the base address to form the effective address.

|              |   |                              |                             |                            |
| :----------- | - | :--------------------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode                       | Offset                      |                            |
|              |   |                              | Direct Register High        | Direct Address Low         |
|              | + |                              |                             | Offset                     |
| Pointer:     | = | `0x00`                       | Pointer Address High        | Pointer Address Low        |
|              |   |                              | Dereferenced Address +1     | Dereferenced Address       |
|              | + | Data Bank Register           | `0x00`                      | `0x00`                     |
|              | + |                              | \[Y Register High\]         | Y Register Low             |
| Operand:     | = | Effective Address bits 23-16 | Effective Address bits 15-8 | Effective Address bits 7-0 |

## Direct Indirect Long Indexed

Mnemonic: `[d],y`

The second byte of the instruction is added to the Direct Page register. This forms a pointer in Bank 0 to the 24 bits of the base address. The Y register is then added to the base address to form the effective address.

|              |   |                              |                             |                            |
| :----------- | - | :--------------------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode                       | Offset                      |                            |
|              |   |                              | Direct Register High        | Direct Address Low         |
|              | + |                              |                             | Offset                     |
| Pointer:     | = | `0x00`                       | Pointer Address High        | Pointer Address Low        |
|              |   | Dereferenced Address +2      | Dereferenced Address +1     | Dereferenced Address       |
|              | + |                              | \[Y Register High\]         | Y Register Low             |
| Operand:     | = | Effective Address bits 23-16 | Effective Address bits 15-8 | Effective Address bits 7-0 |

## Direct Indirect Long

Mnemonic: `[d]`

The second byte of the instruction is added to the Direct Page register. This forms a pointer in Bank 0 to the 24 bits of the effective address. 

|              |   |                              |                             |                            |
| :----------- | - | :--------------------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode                       | Offset                      |                            |
|              |   |                              | Direct Register High        | Direct Address Low         |
|              | + |                              |                             | Offset                     |
| Pointer:     | = | `0x00`                       | Pointer Address High        | Pointer Address Low        |
| Operand:     |   | Dereferenced Address +2      | Dereferenced Address +1     | Dereferenced Address       |

## Direct Indirect

Mnemonic: `(d)`

The second byte of the instruction is added to the Direct Page register. This forms a pointer in Bank 0 to the 16 low-order bits of the effective address. The Data Bank register contains the 8 high-order bits of the effective address.

|              |   |                    |                             |                            |
| :----------- | - | :----------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode             | Offset                      |                            |
|              |   |                    | Direct Register High        | Direct Address Low         |
|              | + |                    |                             | Offset                     |
| Pointer:     | = | `0x00`             | Pointer Address High        | Pointer Address Low        |
| Operand:     |   | Data Bank Register | Dereferenced Address +1     | Dereferenced Address       |

## Direct

Mnemonic: `d`

The second byte of the instruction is added to the Direct Page register to form the 16 low-order bits of the effective address. The 8 high-order bits of the address are always zero.

|              |   |                    |                        |                       |
| :----------- | - | :----------------- | :--------------------- | :-------------------- |
| Instruction: |   | Opcode             | Offset                 |                       |
|              |   |                    | Direct Register High   | Direct Address Low    |
|              | + |                    |                        | Offset                |
| Operand:     | = | `0x00`             | Effective Address High | Effective Address Low |

## Immediate

Mnemonic: `#`

The operand is the second byte (second and third bytes in 16-bit mode) of the instruction.

|              |   |        |                         |                         |
| :----------- | - | :----- | :---------------------- | :---------------------- |
| Instruction: |   | Opcode | Immediate Data Low      | \[Immediate Data High\] |
| Operand:     |   |        | \[Immediate Data High\] | Immediate Data Low      |

## Implied

Mnemonic: `i`

The operand is defined solely by the instruction.

## Program Counter Relative Long

Mnemonic: `rl`

Add the next two bytes of the instruction to the Program Counter, which has been updated to point to the next instruction. With the Branch instruction, the Program Counter is loaded with the result, while with the Push Effective Relative instruction, the result is pushed onto the stack. The offset is a signed 16-bit number from -32768 to 32767. The Program Bank register is not affected.

|              |   |        |                      |                     |
| :----------- | - | :----- | :------------------- | :------------------ |
| Instruction: |   | Opcode | Signed Offset Low    | Signed Offset High  |
|              |   |        | Program Counter High | Program Counter Low |
|              | + |        | Signed Offset High   | Signed Offset Low   |
| Operand:     | = |        | Result High          | Result Low          |

## Program Counter Relative

Mnemonic: `r`

If the branch is taken, add the next byte of the instruction to the Program Counter, which has been updated to point to the next instruction. The offset is a signed 8-bit number from -128 to 127. The Program Bank register is not affected.

|              |   |        |                      |                     |
| :----------- | - | :----- | :------------------- | :------------------ |
| Instruction: |   | Opcode | Signed Offset        |                     |
|              |   |        | Program Counter High | Program Counter Low |
|              | + |        |                      | Signed Offset       |
| Operand:     | = | `0x00` | Result High          | Result Low          |

## Stack

Mnemonic: `s`

The operand is wherever the Stack Pointer register currently points to. The bank address is always 0. Interrupt Vectors are always fetched from Bank 0.

## Stack Relative

Mnemonic: `d,s`

The next byte of the instruction is added to the Stack Pointer. This forms the 16 low bits of the effective address, while the 8 high bits are always zero. The relative offset is an unsigned 8-bit number from 0 to 255.

|              |   |        |                    |                   |
| :----------- | - | :----- | :----------------- | :---------------- |
| Instruction: |   | Opcode | Unsigned Offset    |                   |
|              |   |        | Stack Pointer High | Stack Pointer Low |
|              | + |        |                    | Unsigned Offset   |
| Operand:     | = | `0x00` | Result High        | Result Low        |

## Stack Relative Indirect Indexed

Mnemonic: `(d,s),y`

Add the next byte of the instruction to the Stack Pointer. This forms a pointer to the 16-bit base address in Bank 0. The Data Bank contains the 8 high bits of the base address. The sum of the 24-bit base address and the Y register forms the effective address.

|              |   |                              |                             |                            |
| :----------- | - | :--------------------------- | :-------------------------- | :------------------------- |
| Instruction: |   | Opcode                       | Unsigned Offset             |                            |
|              |   |                              | Stack Pointer High          | Stack Pointer Low          |
|              | + |                              |                             | Unsigned Offset            |
| Pointer:     | = | `0x00`                       | Pointer High                | Pointer Low                |
|              |   | Data Bank Register           | Dereferenced Address +1     | Dereferenced Address       |
|              | + |                              | \[Y Register High\]         | Y Register Low             |
| Operand:     | = | Effective Address bits 23-16 | Effective Address bits 15-8 | Effective Address bits 7-0 |