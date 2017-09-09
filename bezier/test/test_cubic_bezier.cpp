#include "gtest/gtest.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}

TEST(sample_test_case, sample_test)
{
  EXPECT_EQ(1, 1);
}