#include "cpu.h"
#include "unity.h"
#include "unity_internals.h"
#include <stdlib.h>

void setUp(void) {};
void tearDown(void) {};

void test_CPU_should_init() {
  cpu* c = mgec_new_cpu();
  TEST_ASSERT_EQUAL_INT8(0, c->xh);
  TEST_ASSERT_EQUAL_INT8(0, c->yh);
  TEST_ASSERT_EQUAL_INT8(0, c->sr_n);
  TEST_ASSERT_EQUAL_INT8(0, c->sr_v);
  TEST_ASSERT_EQUAL_INT8(1, c->sr_m);
  TEST_ASSERT_EQUAL_INT8(1, c->sr_x);
  TEST_ASSERT_EQUAL_INT8(0, c->sr_d);
  TEST_ASSERT_EQUAL_INT8(1, c->sr_i);
  TEST_ASSERT_EQUAL_INT8(0, c->sr_z);
  TEST_ASSERT_EQUAL_INT8(1, c->sr_c);
  TEST_ASSERT_EQUAL_INT8(1, c->sph);
  TEST_ASSERT_EQUAL_INT8(0, c->dp);
  TEST_ASSERT_EQUAL_INT8(0, c->pb);
  TEST_ASSERT_EQUAL_INT8(0, c->db);
  TEST_ASSERT_EQUAL_INT8(1, c->e);
  free(c);
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_CPU_should_init);

  return UNITY_END();
}