#include <stdbool.h>
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

inline cycles load8(cpu* c, cpu_register_t reg, u8 value) {
  // TODO: flag changes
  // zero out the high byte when in native mode or
  // emulation mode with 8-bit indexers
  bool hbo = (c->e || (c->sr_x || c->sr_m));
  switch (reg) {
  case XL:
    c->xl = value;
    if (hbo)
      c->xh = 0;
    break;
  case YL:
    c->yl = value;
    if (hbo)
      c->yh = 0;
    break;
  // TODO: some error condition
  case X:
  case XH:
  case Y:
  case YH:
  case A:
  case B:
  case C:
  default:
    break;
  }

  if (value == 0) {
    c->sr_z = 1;
  } else {
    c->sr_z = 0;
  }

  return 1;
}

inline cycles load16(cpu* c, cpu_register_t reg, u16 value) {
  // TODO: flag changes
  switch (reg) {
  case X:
    c->x = value;
    break;
  case Y:
    c->y = value;
    break;
  case C:
    c->c = value;
  // TODO: some error condition
  case XL:
  case XH:
  case YL:
  case YH:
  case A:
  case B:
  default:
    break;
  }

  if (value == 0) {
    c->sr_z = 1;
  } else {
    c->sr_z = 0;
  }

  return 2;
}
