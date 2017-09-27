#ifndef BEZIER_CUBIC_BEZIER_H
#define BEZIER_CUBIC_BEZIER_H
#include <Eigen/Core>

using Eigen::Vector3f;

namespace bezier {
	class CubicBezier {
	  public:
        CubicBezier(const Vector3f& point_a, const Vector3f& point_b,
        const Vector3f& handle_a, const Vector3f& handle_b);
        Vector3f Interpolate(float t) const;

        Vector3f const& pointA() const;
	    void pointA(Vector3f const& point_a);

        Vector3f const& pointB() const;
        void pointB(Vector3f const& point_b);

        Vector3f const& handleA() const;
        void handleA(Vector3f const& handle_a);

        Vector3f const& handleB() const;
        void handleB(Vector3f const& handle_a);

    private:
        Vector3f _point_a;
        Vector3f _point_b;
        Vector3f _handle_a;
        Vector3f _handle_b;
  };
} // namespace bezier
#endif //BEZIER_CUBIC_BEZIER_H

