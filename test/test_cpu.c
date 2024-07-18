#include "cpu.h"
#include "types.h"
#include "unity.h"
#include "unity_internals.h"
#include <stdlib.h>

void setUp(void){};
void tearDown(void){};

void test_CPU_should_init() {
  cpu* c = mgec_new_cpu();
  TEST_ASSERT_EQUAL_INT8(0, c->xh);
  TEST_ASSERT_EQUAL_INT8(0, c->yh);
  TEST_ASSERT_EQUAL_INT8(0x35, c->sr);
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

void test_CPU_load8() {
  cpu* c = mgec_new_cpu();
  u8 value = 242;
  cycles cyc = load(c, XL, value);
  TEST_ASSERT_EQUAL_INT8(242, c->xl);
  TEST_ASSERT_EQUAL_size_t(1, cyc);
  // Maybe?
  TEST_ASSERT_EQUAL_INT8(0x00, c->xh);
  TEST_ASSERT_EQUAL(0, c->sr_z);
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_CPU_should_init);
  RUN_TEST(test_CPU_load8);

  return UNITY_END();
}
