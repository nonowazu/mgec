#include <stdlib.h>

#include "cpu.h"

cpu *mgec_new_cpu() {
  // TODO: more comprehensive cpu init
  cpu *c = malloc(sizeof(cpu));
  if (c == NULL)
    return NULL;

  c->pc = 0;
  c->ac = 0;
  c->x = 0;
  c->y = 0;
  c->sr = 0;
  c->sp = 0;

  return c;
}