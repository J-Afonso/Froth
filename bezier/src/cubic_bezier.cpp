#include "cubic_bezier.h"

#include <math.h> 

namespace bezier {
  
  CubicBezier::CubicBezier(const Vector3f& point_a, const Vector3f& point_b,
    const Vector3f& handle_a, const Vector3f& handle_b) : _point_a(point_a),
    _point_b(point_b), _handle_a (handle_a), _handle_b(handle_b){
  }

  Vector3f CubicBezier::Interpolate(const float t) {
    float inverted_t = (1 - t);
    Vector3f p0 = pow(inverted_t, 3) * _point_a;
    Vector3f p1 = 3 * pow(inverted_t, 2) * t * _handle_a;
    Vector3f p2 = 3 * inverted_t * pow(t, 2) * _handle_b;
    Vector3f p3 = pow(t, 3) * _point_b;
    return p0 + p1 + p2 + p3;
  }

} // namespace bezier

