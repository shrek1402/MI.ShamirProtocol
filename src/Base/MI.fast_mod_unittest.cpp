
#include <gtest/gtest.h>

template<class Ty>
struct already_false : std::false_type {};

TEST(FastMod, NumberBits) {
  // GTEST_ASSERT_EQ(mi::internal::number_bits(0), 0);
  // GTEST_ASSERT_EQ(mi::internal::number_bits(7), 3);
  // GTEST_ASSERT_EQ(mi::internal::number_bits(8), 4);
  // GTEST_ASSERT_EQ(mi::internal::number_bits(15), 4);
  GTEST_ASSERT_FALSE(already_false<int>::value);
}

TEST(FastMod, NumberBits1) {
  int a;
}