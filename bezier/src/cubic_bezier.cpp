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

    Vector3f const &CubicBezier::pointA() const {
        return _point_a;
    }

    void CubicBezier::pointA(Vector3f const &point_a) {
        _point_a = point_a;
    }

    Vector3f const &CubicBezier::pointB() const {
        return _point_b;
    }

    void CubicBezier::pointB(Vector3f const &point_b) {
        _point_b = point_b;
    }

    Vector3f const &CubicBezier::handleA() const {
        return _handle_a;
    }

    void CubicBezier::handleA(Vector3f const &handle_a) {
        _handle_a = handle_a;
    }

    Vector3f const &CubicBezier::handleB() const {
        return _handle_b;
    }

    void CubicBezier::handleB(Vector3f const &handle_b) {
        _handle_b = handle_b;
    }

} // namespace bezier

