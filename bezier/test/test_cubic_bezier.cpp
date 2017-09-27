#include "gtest/gtest.h"
#include "cubic_bezier.h"

using Eigen::Vector3f;

constexpr double kEigenTolerance = 1e-4;

#define EXPECT_EIGEN_EQ(x, n, c) EXPECT_TRUE( ((x)-(n)).norm() < (c) )

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(TEST_CUBIC_BEZIER, test_bezier_0) {
  bezier::CubicBezier cubic_bezier(Vector3f(0,0,0), Vector3f(1,0,0), Vector3f(0,1,0), Vector3f(1,1,0));  
  EXPECT_EIGEN_EQ(Vector3f(0, 0, 0), cubic_bezier.Interpolate(0), kEigenTolerance);
}

TEST(TEST_CUBIC_BEZIER, test_bezier_1) {
  bezier::CubicBezier cubic_bezier(Vector3f(0, 0, 0), Vector3f(1, 0, 0), Vector3f(0, 1, 0), Vector3f(1, 1, 0));
  EXPECT_EIGEN_EQ(Vector3f(1, 0, 0), cubic_bezier.Interpolate(1), kEigenTolerance);
}

TEST(TEST_CUBIC_BEZIER, test_bezier_0_5) {
  bezier::CubicBezier cubic_bezier(Vector3f(0, 0, 0), Vector3f(1, 0, 0), Vector3f(0, 1, 0), Vector3f(1, 1, 0));
  EXPECT_EIGEN_EQ(Vector3f(0.5, 0.75, 0), cubic_bezier.Interpolate(0.5), kEigenTolerance);
}