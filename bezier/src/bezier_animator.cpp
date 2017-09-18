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
    // Get relative time;
    float relative_time = _current_time / _duration;
    //Vector3f lula = _start.getPointA();
    //_result.setPointA(_start.getPointA())
  }
}