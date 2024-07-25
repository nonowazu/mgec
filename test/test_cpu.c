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
  // 0b11110010
  // negative: true
  // zero: false
  u8 value = 242;
  cycles cyc = load(c, XL, value);
  TEST_ASSERT_EQUAL_INT8(242, c->xl);
  TEST_ASSERT_EQUAL_size_t(1, cyc);
  TEST_ASSERT_EQUAL_INT8(0x00, c->xh);
  // Checking for zero
  TEST_ASSERT_FALSE(c->sr_z);
  // Checking for negative
  TEST_ASSERT_TRUE(c->sr_n);
  // 0b00000000
  // negative: false
  // zero: true
  value = 0;
  cyc = load(c, YL, value);
  TEST_ASSERT_EQUAL_INT8(0, c->yl);
  TEST_ASSERT_EQUAL_size_t(1, cyc);
  TEST_ASSERT_EQUAL_INT8(0x00, c->yh);
  // Checking for zero
  TEST_ASSERT_TRUE(c->sr_z);
  // Checking for negative
  TEST_ASSERT_FALSE(c->sr_n);

  // let's also recheck the xl register for overwrites
  TEST_ASSERT_EQUAL_INT8(242, c->xl);
  TEST_ASSERT_EQUAL_INT8(0x00, c->xh);

  free(c);
}

void test_CPU_trans() {
  cpu* c = mgec_new_cpu();
  u8 value = 4;
  load(c, A, value);
  trans8(c, A, XL);

  TEST_ASSERT_EQUAL_INT8(4, c->xl);
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_CPU_should_init);
  RUN_TEST(test_CPU_load8);
  RUN_TEST(test_CPU_trans);

  return UNITY_END();
}
