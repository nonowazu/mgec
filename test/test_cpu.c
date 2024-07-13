#include "cpu.h"
#include "unity.h"
#include "unity_internals.h"

void setUp(void){};
void tearDown(void){};

void test_CPU_should_init() {
  cpu *c = mgec_new_cpu();
  TEST_ASSERT_EQUAL_INT16(c->pc, 0);
  TEST_ASSERT_EQUAL_INT8(c->ac, 0);
  TEST_ASSERT_EQUAL_INT8(c->x, 0);
  TEST_ASSERT_EQUAL_INT8(c->y, 0);
  TEST_ASSERT_EQUAL_INT8(c->sr, 0);
  TEST_ASSERT_EQUAL_INT8(c->sp, 0);
}

int main() {
  UNITY_BEGIN();

  RUN_TEST(test_CPU_should_init);

  return UNITY_END();
}