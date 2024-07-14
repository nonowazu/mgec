#include "cpu.h"
#include "unity.h"
#include "unity_internals.h"

void setUp(void) {};
void tearDown(void) {};

void test_CPU_should_init() {
  cpu* c = mgec_new_cpu();
  TEST_ASSERT_EQUAL_INT8(c->xh, 0);
  TEST_ASSERT_EQUAL_INT8(c->yh, 0);
  TEST_ASSERT_EQUAL_INT8(c->sr, 0x35);
  TEST_ASSERT_EQUAL_INT8(c->sph, 1);
  TEST_ASSERT_EQUAL_INT8(c->dp, 0);
  TEST_ASSERT_EQUAL_INT8(c->pb, 0);
  TEST_ASSERT_EQUAL_INT8(c->db, 0);
  TEST_ASSERT_EQUAL_INT8(c->e, 1);
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_CPU_should_init);

  return UNITY_END();
}