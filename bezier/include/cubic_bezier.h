#ifndef BEZIER_CUBIC_BEZIER_H
#define BEZIER_CUBIC_BEZIER_H
#include <Eigen/Core>

using Eigen::Vector3f;

namespace bezier {
	class CubicBezier {
	  public:
      CubicBezier(const Vector3f& point_a, const Vector3f& point_b,
        const Vector3f& handle_a, const Vector3f& handle_b);		  
      Vector3f Interpolate(const float t) const;
	  private:
		  Vector3f _point_a;
		  Vector3f _point_b;
		  Vector3f _handle_a;
		  Vector3f _handle_b;
	  };
} // namespace bezier
#endif //BEZIER_CUBIC_BEZIER_H

