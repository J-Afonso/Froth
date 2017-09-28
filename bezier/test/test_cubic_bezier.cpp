#include "gtest/gtest.h"
#include "cubic_bezier.h"

using Eigen::Vector3f;

constexpr double kEigenTolerance = 1e-4;

#define EXPECT_EIGEN_EQ(x, n, c) EXPECT_TRUE( ((x)-(n)).norm() < (c) )

TEST(TEST_CUBIC_BEZIER, test_bezier) {
  bezier::CubicBezier cubic_bezier(Vector3f(0,0,0), Vector3f(1,0,0), Vector3f(0,1,0), Vector3f(1,1,0));  
  EXPECT_EIGEN_EQ(Vector3f(0, 0, 0), cubic_bezier.Interpolate(0), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(1, 0, 0), cubic_bezier.Interpolate(1), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(0.5, 0.75, 0), cubic_bezier.Interpolate(0.5), kEigenTolerance);
}