#include "bezier_path_animator.h"
#include <glog/logging.h>

bezier::BezierPathAnimator::BezierPathAnimator(const BezierPath &start, const BezierPath &end,
                                               float duration) :
  _start(start), _end(end), _duration(duration), _current(start) {
  CHECK_EQ(_start.Points().size(), _end.Points().size());
  CHECK_GT(_duration, 0);
};

BezierPath bezier::BezierPathAnimator::Get() const
{
  return _current;
}

void bezier::BezierPathAnimator::Tick(float time_since_last_frame) {
  _current_time += time_since_last_frame;
  if (_current_time > _duration) {
    // Cap the time to the duration.
    _current_time = _duration;
  } else {
    // Linear Interpolation: F(x) = A + t (B - A)
    float relative_time = _current_time / _duration;
    _current.Clear();
    for (uint16_t i=0; i < _start.Points().size(); ++i) {
      BezierPoint start = _start.Points()[i];
      BezierPoint end = _end.Points()[i];

      BezierPoint point;
      point.point = start.point + relative_time * (end.point - start.point);
      point.handle_a = start.handle_a + relative_time * (end.handle_a - start.handle_a);
      point.handle_b = start.handle_b + relative_time * (end.handle_b - start.handle_b);

      _current.Add(point);
    }
  }
}