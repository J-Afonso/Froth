#include "bezier_animator.h"

CubicBezier bezier::BezierAnimator::get() const
{
  return _current;
}

void bezier::BezierAnimator::tick(const float time_since_last_frame) {
  _current_time += time_since_last_frame;
  if (_current_time > _duration) {
    // Cap the time to the duration.
    _current_time = _duration;
  } else {
    // Linear Interpolation: F(x) = A + t (B - A)
    float relative_time = _current_time / _duration;
    _current.handleA(_start.handleA() + relative_time * (_end.handleA() - _start.handleA()));
    _current.handleB(_start.handleB() + relative_time * (_end.handleB() - _start.handleB()));
    _current.pointA(_start.pointA() + relative_time * (_end.pointA() - _start.pointA()));
    _current.pointB(_start.pointB() + relative_time * (_end.pointB() - _start.pointB()));
  }
}