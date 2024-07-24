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
  setReg(c, reg, value);
  // zero out the high byte when in native mode or
  // emulation mode with 8-bit indexers
  // TODO: change generic to target on enum type instead of value type
  if ((c->e || c->sr_x) && (reg == XL || reg == YL))
    setReg(c, reg + 1, (u8)0);

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
  setReg(c, reg, value);

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

inline cycles trans16(cpu* c, cpu_register16_t reg1, cpu_register16_t reg2) {
  if (reg1 == reg2)
    return 0;

  u16 v1 = fetchReg(c, reg1);
  u16 v2 = fetchReg(c, reg2);
  setReg(c, reg1, v2);
  setReg(c, reg2, v1);

  return 2;
}

inline cycles trans8(cpu* c, cpu_register8_t reg1, cpu_register8_t reg2) {
  if (reg1 == reg2)
    return 0;

  u8 v1 = fetchReg(c, reg1);
  u8 v2 = fetchReg(c, reg2);
  setReg(c, reg1, v2);
  setReg(c, reg2, v1);

  return 2;
}
