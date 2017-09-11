#include "cubic_bezier.h"

namespace bezier {
  
  CubicBezier::CubicBezier(const Vector3f& point_a, const Vector3f& point_b,
    const Vector3f& handle_a, const Vector3f& handle_b) : _point_a(point_a),
    _point_b(point_b), _handle_a (handle_a), _handle_b(handle_b){
  }

  Vector3f CubicBezier::Interpolate(const float t) const{
    float inverted_t = (1 - t);
    return pow(inverted_t, 3) * _point_a 
      + 3 * pow(inverted_t, 2) * t * _handle_a
      + 3 * inverted_t * pow(t, 2) * _handle_b 
      + pow(t, 3) * _point_b;
  }

} // namespace bezier

