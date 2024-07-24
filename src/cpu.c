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

inline u8 fetchReg8(cpu* c, cpu_register8_t reg) {
  switch (reg) {
  case XL:
    return c->xl;
    break;
  case XH:
    return c->xh;
    break;
  case YL:
    return c->yl;
    break;
  case YH:
    return c->yh;
    break;
  case A:
    return c->a;
    break;
  case B:
    return c->b;
    break;
  }
}

inline u16 fetchReg16(cpu* c, cpu_register16_t reg) {
  switch (reg) {
  case X:
    return c->x;
    break;
  case Y:
    return c->y;
    break;
  case C:
    return c->c;
    break;
  }
  // TODO: better handling
  return 0;
}

inline void setReg8(cpu* c, cpu_register8_t reg, u8 value) {
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
  case A:
    c->a = value;
    break;
  case B:
    c->b = value;
    break;
  }
}

inline void setReg16(cpu* c, cpu_register16_t reg, u16 value) {
  switch (reg) {
  case X:
    c->x = value;
    break;
  case Y:
    c->y = value;
    break;
  case C:
    c->c = value;
    break;
  }
}

inline cycles load8(cpu* c, cpu_register8_t reg, u8 value) {
  setReg8(c, reg, value);
  // zero out the high byte when in native mode or
  // emulation mode with 8-bit indexers
  if ((c->e || c->sr_x) && (reg == XL || reg == YL)) {
    switch (reg) {
    case XL:
      setReg8(c, XH, 0);
      break;
    case YH:
      setReg8(c, YH, 0);
      break;
    // cases we don't care about
    case XH:
    case YL:
    case A:
    default:
      break;
    }
  }

  if (value == 0) {
    c->sr_z = 1;
  } else {
    c->sr_z = 0;
  }

  if (value & 0x80) {
    c->sr_n = 1;
  } else {
    c->sr_n = 0;
  }

  return 1;
}

inline cycles load16(cpu* c, cpu_register16_t reg, u16 value) {
  setReg16(c, reg, value);

  if (value == 0) {
    c->sr_z = 1;
  } else {
    c->sr_z = 0;
  }

  if (value & 0x8000) {
    c->sr_n = 1;
  } else {
    c->sr_n = 0;
  }

  return 2;
}

inline cycles trans16(cpu* c, cpu_register16_t src, cpu_register16_t dest) {
  if (src == dest)
    return 0;

  u16 value = fetchReg16(c, src);
  setReg16(c, dest, value);

  if (value == 0) {
    c->sr_z = 1;
  } else {
    c->sr_z = 0;
  }

  if (value & MGEC_16_NEGATIVE) {
    c->sr_n = 1;
  } else {
    c->sr_n = 0;
  }

  return 2;
}

inline cycles trans8(cpu* c, cpu_register8_t src, cpu_register8_t dest) {
  if (src == dest)
    return 0;

  u8 value = fetchReg8(c, src);
  setReg8(c, dest, value);

  if (value == 0) {
    c->sr_z = 1;
  } else {
    c->sr_z = 0;
  }

  if (value & MGEC_8_NEGATIVE) {
    c->sr_n = 1;
  } else {
    c->sr_n = 0;
  }

  return 2;
}
