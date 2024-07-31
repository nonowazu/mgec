#ifndef MGEC_ADDRESSING_H
#define MGEC_ADDRESSING_H

#include "types.h"

typedef enum _addressing_mode {
  // a
  //
  // The next two bytes of the instruction are the 16 low bits of the effective
  // address. The Data Bank register contains the 8 high bits of the address.
  ABSOLUTE,
  // (a,x)
  //
  // Add the next two bytes of the instruction to the X register to form a
  // pointer in bank 0. The contents of this pointer are then used for whichever
  // the instruction does.
  ABSOLUTE_INDEXED_INDIRECT,
  // a,x
  //
  // Add the next two bytes of the instruction to the X register. The Data Bank
  // register contains the 8 high bits of the address.
  ABSOLUTE_INDEXED_WITH_X,
  // a,y
  //
  // Add the next two bytes of the instruction to the Y register. The Data Bank
  // register contains the 8 high bits of the address.
  ABSOLUTE_INDEXED_WITH_Y,
  // (a)
  //
  // The next two bytes of the instruction form a pointer to an address in bank
  // 0. The contents of this pointer are then used for whichever the instruction
  // does.
  ABSOLUTE_INDIRECT,
  // al,x
  //
  // Add the next three bytes of the instruction to the X register to form a
  // 24-bit address.
  ABSOLUTE_LONG_INDEXED_WITH_X,
  // al
  //
  // The next three bytes of the instruction form a 24-bit address.
  ABSOLUTE_LONG,
  // A
  //
  // The operand is not found in the next few bytes of instructions, but is the
  // accumulator.
  ACCUMULATOR,
  // xyc
  //
  // The second byte of the instruction is the destination bank. The third byte
  // of the instruction is the source bank. The Y register contains the 16 low
  // bits of the destination address, and the X register contains the 16 low
  // bits of the source address. The accumulator contains one less than the
  // number of bytes to move.
  BLOCK_MOVE,
  // (d,x)
  //
  // Add the second byte of the instruction to the sum of the Direct Page
  // register and the X register. The result is a pointer to the 16 low bits of
  // the effective address. The Data Bank register contains the 8 high bits of
  // the effective address.
  DIRECT_INDEXED_INDIRECT,
  // d,x
  //
  // Add the second byte of the instruction to the sum of the Direct Page
  // register and the X register to form the 16 low bits of the effective
  // address. The 8 high bits of the effective address are always 0.
  DIRECT_INDEXED_WITH_X,
  // d,y
  //
  // Add the second byte of the instruction to the sum of the Direct Page
  // register and the Y register to form the 16 low bits of the effective
  // address. The 8 high bits of the effective address are always 0.
  DIRECT_INDEXED_WITH_Y,
  // (d),y
  //
  // Add the second byte of the instruction to the Direct Page register. This
  // forms a pointer to the 16 low bits of the base address. The 8 high bits are
  // found in the Data Bank register. Add this 24 bit address to the Y register
  // to attain the effective address.
  DIRECT_INDIRECT_INDEXED,
  // [d],y
  //
  // Add the second byte of the instruction to the Direct Page register. This
  // forms a pointer to a 24-bit address, which when added with the Y register
  // results in the effective address.
  DIRECT_INDIRECT_LONG_INDEXED,
  // [d]
  //
  // Add the second byte of the instruction to the Direct Page register. This
  // forms the 16 low bits of a pointer, with the 8 high bits being 0, which
  // points to the 24-bit effective address.
  DIRECT_INDIRECT_LONG,
  // (d)
  //
  // Add the second byte of the instruction to the Direct Page register. This
  // forms a pointer to the 16 low bits of the effective address. The Data Bank
  // register holds the 8 high bits of the effective address.
  DIRECT_INDIRECT,
  // d
  //
  // Add the second byte of the instruction to the Direct Page register. This is
  // the effective address, as the bank register is always 0.
  DIRECT,
  // #
  //
  // The operand is the second (or second and third byte in 16-bit mode) of the
  // instruction.
  IMMEDIATE,
  // i
  //
  // The operand is defined by the instruction.
  IMPLIED,
  // rl
  //
  // Add the next two bytes of the instruction to the Program Counter, which has
  // been updated to point to the next instruction. With the Branch instruction,
  // the Program Counter is loaded with the result, while with the Push
  // Effective Relative instruction, the result is pushed onto the stack. The
  // offset is a signed 16-bit number from -32768 to 32767. The Program Bank
  // register is not affected.
  PROGRAM_COUNTER_RELATIVE_LONG,
  // r
  //
  // If the branch is taken, add the next byte of the instruction to the Program
  // Counter, which has been updated to point to the next instruction. The
  // offset is a signed 8-bit number from -128 to 127. The Program Bank register
  // is not affected.
  PROGRAM_COUNTER_RELATIVE,
  // s
  //
  // The operand is wherever the Stack Pointer register currently points to. The
  // bank address is always 0.
  STACK,
  // d,s
  //
  // Add the next byte of the instruction to the Stack Pointer. This forms the
  // 16 low bits of the effective address, while the 8 high bits are always
  // zero. The relative offset is an unsigned 8-bit number from 0 to 255.
  STACK_RELATIVE,
  // (d,s),y
  //
  // Add the next byte of the instruction to the Stack Pointer. This forms a
  // pointer to the 16-bit base address in Bank 0. The Data Bank contains the 8
  // high bits of the base address. The sum of the 24-bit base address and the Y
  // register forms the effective address.
  STACK_RELATIVE_INDIRECT_INDEXED
} addressing_mode_t;

// Looks up and returns the correct addressing mode for the wanted opcode.
addressing_mode_t get_addressing_mode_from_opcode(u8 opcode);

#endif