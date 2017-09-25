#include "gtest/gtest.h"
#include "bezier_path.h"

using bezier::BezierPath;
using bezier::BezierPoint;

#define EXPECT_EIGEN_EQ(x, n, c) EXPECT_TRUE( (x-n).norm() < c )

constexpr double kEigenTolerance = 1e-4;

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(TEST_BEZIER_PATH, test_bezier_path) {

    BezierPath path;

    BezierPoint point_1;
    point_1.point = Vector3f(-1, -1, 0);
    point_1.handle_a = Vector3f(-0.8, -1, 0);
    path.Add(point_1);

    BezierPoint point_2;
    point_2.point = Vector3f(0, 1, 0);
    point_2.handle_a = Vector3f(-0.2, 1, 0);
    point_2.handle_b = Vector3f(0.2, 1, 0);
    path.Add(point_2);

    BezierPoint point_3;
    point_3.point = Vector3f(1, -1, 0);
    point_3.handle_a = Vector3f(0.8, -1, 0);
    path.Add(point_3);


    EXPECT_EIGEN_EQ(point_1.point, path.Get(0), kEigenTolerance);
    EXPECT_EIGEN_EQ(point_2.point, path.Get(0.5), kEigenTolerance);
    EXPECT_EIGEN_EQ(point_3.point, path.Get(1.0), kEigenTolerance);
}
