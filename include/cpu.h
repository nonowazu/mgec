#ifndef MGEC_CPU_H
#define MGEC_CPU_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;

typedef struct _cpu {
  u16 pc;
  u8 ac;
  u8 x, y;
  u8 sr;
  u8 sp;
} cpu;

cpu *mgec_new_cpu();

#endif