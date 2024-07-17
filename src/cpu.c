#include <stdlib.h>

#include "cpu.h"

cpu* mgec_new_cpu() {
  // TODO: more comprehensive cpu init
  cpu* c = malloc(sizeof(cpu));
  if (c == NULL)
    return NULL;

  c->xh = 0;
  c->yh = 0;
  c->sr = MGEC_CPU_STATUS_IDX_SIZE | MGEC_CPU_STATUS_ACC_SIZE |
          MGEC_CPU_STATUS_IRQ_DISABLE | MGEC_CPU_STATUS_CARRY;
  c->sph = 0x01;
  c->dp = 0;
  c->pb = 0;
  c->db = 0;
  c->e = 1;

  return c;
}

#define load(C, R, V) _Generic((V), u8: load8, u16: load16)(C, R, V)

static inline cycles load8(cpu* c, cpu_register_t reg, u8 value) {
  switch (reg) {
  case XL:
    c->xl = value;
    break;
  case XH:
    c->xh = value;
    break;
  case YL:
    c->yl = value;
    break;
  case YH:
    c->yh = value;
    break;
  // Making sure we're handling all cases
  // TODO: some error condition
  case X:
  case Y:
  case A:
  case B:
  case C:
  default:
    break;
  }

  return 1;
}

static inline cycles load16(cpu* c, cpu_register_t reg, u16 value) {
  switch (reg) {
  case X:
    c->x = value;
    break;
  case Y:
    c->y = value;
    break;
  // TODO: some error condition
  case XL:
  case XH:
  case YL:
  case YH:
  case A:
  case B:
  case C:
  default:
    break;
  }

  return 1;
}