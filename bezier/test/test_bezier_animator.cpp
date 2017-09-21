#include "gtest/gtest.h"
#include "cubic_bezier.h"
#include "bezier_animator.h"

using Eigen::Vector3f;
using bezier::CubicBezier;
using bezier::BezierAnimator;

#define EXPECT_EIGEN_EQ(x, n, c) EXPECT_TRUE( (x-n).norm() < c )

constexpr double kEigenTolerance = 1e-4;

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(TEST_BEZIER_ANIMATOR, test_bezier_animator) {
  CubicBezier start(Vector3f(-1, -1, 0), Vector3f(1, 1, 0), Vector3f(0, -1, 0), Vector3f(0, 1, 0));
  CubicBezier end(Vector3f(-1, 1, 0), Vector3f(1, -1, 0), Vector3f(-1, 0, 0), Vector3f(1, 0, 0));

  BezierAnimator bezier_animator(start, end, 2000);

  CubicBezier initial_bezier = bezier_animator.get();

  EXPECT_EIGEN_EQ(Vector3f(-1,  -1, 0), initial_bezier.Interpolate(0), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(1, 1, 0), initial_bezier.Interpolate(1), kEigenTolerance);

  bezier_animator.tick(1000);
  CubicBezier half_bezier = bezier_animator.get();

  EXPECT_EIGEN_EQ(Vector3f(-1, 0, 0), half_bezier.Interpolate(0), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(1, 0, 0), half_bezier.Interpolate(1), kEigenTolerance);

  EXPECT_EIGEN_EQ(Vector3f(-0.5, -0.5, 0), half_bezier.handleA(), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(0.5, 0.5, 0), half_bezier.handleB(), kEigenTolerance);

  bezier_animator.tick(1000);
  CubicBezier final_bezier = bezier_animator.get();

  EXPECT_EIGEN_EQ(Vector3f(-1, 1, 0), final_bezier.Interpolate(0), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(1, -1, 0), final_bezier.Interpolate(1), kEigenTolerance);

  EXPECT_EIGEN_EQ(Vector3f(-1, 0, 0), final_bezier.handleA(), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(1, 0, 0),  final_bezier.handleB(), kEigenTolerance);
}
