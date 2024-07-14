#ifndef MGEC_CPU_H
#define MGEC_CPU_H

#define MGEC_CPU_STATUS_NEGATIVE 0b10000000
#define MGEC_CPU_STATUS_OVERFLOW 0b01000000
#define MGEC_CPU_STATUS_ACC_SIZE 0b00100000
#define MGEC_CPU_STATUS_IDX_SIZE 0b00010000
#define MGEC_CPU_STATUS_DECIMAL 0b00001000
#define MGEC_CPU_STATUS_IRQ_DISABLE 0b00000100
#define MGEC_CPU_STATUS_ZERO 0b00000010
#define MGEC_CPU_STATUS_CARRY 0b00000001

#include "types.h"

// The 65C816 CPU
typedef struct _cpu {
  // The 65C816 accumulator.
  // In 8-bit mode, the only way to access the B register is by swapping its
  // content with the A register. In 16-bit mode, the B and A registers are
  // ganged to form the MSB and LSB respectively of the C register.
  union {
    struct {
      u8 b;
      u8 a;
    };
    u16 ac;
  };

  union {
    struct {
      // High byte of the X index register
      u8 xh;
      // Low byte of the X index register
      u8 xl;
    };
    // X index register
    u16 x;
  };

  union {
    struct {
      // High byte of the Y index register
      u8 yh;
      // Low byte of the Y index register
      u8 yl;
    };
    // Y index register
    u16 y;
  };

  union {
    struct {
      // Negative
      u8 sr_n : 1;
      // oVerflow
      u8 sr_v : 1;
      // accuMulator register size (native mode only; 0 = 16-bit, 1 = 8-bit)
      u8 sr_m : 1;
      // indeX register size (native mode only; 0 = 16-bit, 1 = 8-bit)
      u8 sr_x : 1;
      // Decimal mode
      u8 sr_d : 1;
      // Irq disable
      u8 sr_i : 1;
      // Zero
      u8 sr_z : 1;
      // Carry
      u8 sr_c : 1;
    };
    // The 65C816 status register.
    u8 sr;
  };

  // Emulation mode flag
  // (This didn't fit in the status register back in the day, and you could only
  // ever change the value in here by exchanging the carry flag with it.)
  u8 e : 1;

  union {
    struct {
      // High byte of the stack pointer. Set to 1 in emulation mode.
      u8 sph;
      // Low byte of the stack pointer.
      u8 spl;
    };
    u16 sp;
  };

  // Direct Page pointer
  u16 dp;
  // Data bank register
  u8 db;
  // Program bank register
  u8 pb;
  // Program counter
  u16 pc;
} cpu;

cpu* mgec_new_cpu();

#endif