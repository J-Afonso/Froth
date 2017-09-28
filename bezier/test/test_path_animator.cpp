#include "gtest/gtest.h"
#include "cubic_bezier.h"
#include "bezier_path_animator.h"

using Eigen::Vector3f;
using bezier::BezierPoint;
using bezier::BezierPath;
using bezier::BezierPathAnimator;

#define EXPECT_EIGEN_EQ(x, n, c) EXPECT_TRUE( ((x)-(n)).norm() < (c) )

constexpr double kEigenTolerance = 1e-4;

TEST(TEST_BEZIER_ANIMATOR, test_bezier_animator) {
  BezierPath start;

  BezierPoint start_1;
  start_1.point = Vector3f(-1, -1, 0);
  start_1.handle_b = Vector3f(-0.8f, -1, 0);
  start.Add(start_1);

  BezierPoint start_2;
  start_2.point = Vector3f(0, 1, 0);
  start_2.handle_a = Vector3f(-0.2f, 1, 0);
  start_2.handle_b = Vector3f(0.2f, 1, 0);
  start.Add(start_2);

  BezierPoint start_3;
  start_3.point = Vector3f(1, -1, 0);
  start_3.handle_a = Vector3f(0.8f, -1, 0);
  start.Add(start_3);

  BezierPath end;

  BezierPoint end_1;
  end_1.point = Vector3f(-1, 1, 0);
  end_1.handle_a = Vector3f(-0.8f, 1, 0);
  end.Add(end_1);

  BezierPoint end_2;
  end_2.point = Vector3f(0, -1, 0);
  end_2.handle_a = Vector3f(-0.2f, -1, 0);
  end_2.handle_b = Vector3f(0.2f, -1, 0);
  end.Add(end_2);

  BezierPoint end_3;
  end_3.point = Vector3f(1, 1, 0);
  end_3.handle_a = Vector3f(0.8f, 1, 0);
  end.Add(end_3);

  BezierPathAnimator bezier_animator(start, end, 2000);

  BezierPath initial_path = bezier_animator.Get();

  EXPECT_EIGEN_EQ(start_1.point, initial_path.Get(0), kEigenTolerance);
  EXPECT_EIGEN_EQ(start_2.point, initial_path.Get(0.5f), kEigenTolerance);
  EXPECT_EIGEN_EQ(start_3.point, initial_path.Get(1), kEigenTolerance);

  bezier_animator.Tick(1000);
  BezierPath half_path = bezier_animator.Get();

  EXPECT_EIGEN_EQ(Vector3f(-1, 0, 0), half_path.Get(0), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(0, 0, 0), half_path.Get(0.5), kEigenTolerance);
  EXPECT_EIGEN_EQ(Vector3f(1, 0, 0), half_path.Get(1), kEigenTolerance);

  bezier_animator.Tick(1000);
  BezierPath final_path = bezier_animator.Get();

  EXPECT_EIGEN_EQ(end_1.point, final_path.Get(0), kEigenTolerance);
  EXPECT_EIGEN_EQ(end_2.point, final_path.Get(0.5), kEigenTolerance);
  EXPECT_EIGEN_EQ(end_3.point, final_path.Get(1), kEigenTolerance);

}
