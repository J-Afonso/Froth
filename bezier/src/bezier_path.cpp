#include "bezier_path.h"
#include <glog/logging.h>

void bezier::BezierPath::Add(const bezier::BezierPoint &point) {
  _points.push_back(point);
  _dirty = true;
}

Vector3f bezier::BezierPath::Get(float t) {
  CHECK_GE(t, 0);
  CHECK_LE(t, 1);
  if (_dirty) {
    // Recalculate the path.
    _bezier_path.clear();
    for (int i = 1; i < _points.size(); ++i) {
      const BezierPoint previous_point = _points[i - 1];
      const BezierPoint point = _points[i];
      CubicBezier bezier(previous_point.point, point.point, previous_point.handle_b,
                         point.handle_a);
      _bezier_path.push_back(bezier);
    }
    _dirty = false;
  }

  float relative_duration = t * (float)_bezier_path.size();
  auto bezier_index = (unsigned long) relative_duration;
  if (bezier_index > _bezier_path.size() - 1) {
    bezier_index = _bezier_path.size() - 1;
  }
  float relative_progress = relative_duration - bezier_index;

  return _bezier_path.at(bezier_index).Interpolate(relative_progress);
}

void bezier::BezierPath::Clear() {
  _points.clear();
  _dirty = true;
}

std::vector<bezier::BezierPoint> bezier::BezierPath::Points() const {
  return _points;
}
