#include "bezier_path.h"

void bezier::BezierPath::Add(const bezier::BezierPoint &point) {
  _points.push_back(point);
  _dirty = true;
}

Vector3f bezier::BezierPath::Get(const float t) {
  //TODO(j-afonso): Add range checks.
  //CHECK_RANGE(t, 0, 1);
  if (_dirty) {
    // Recalculate the path.
    _bezier_path.clear();
    for (int i = 1; i < _points.size(); ++i) {
      const BezierPoint previous_point = _points[i - 1];
      const BezierPoint point = _points[i];
      // TODO(j-afonso): CHECK IF ALL THE HANDLES ARE FILLED UP.
      CubicBezier bezier(previous_point.point, point.point, previous_point.handle_b,
                         point.handle_a);
      _bezier_path.push_back(bezier);
    }
    _dirty = false;
  }

  double relative_duration = t * (double)_bezier_path.size();
  int bezier_index = (int)relative_duration;
  if (bezier_index > _bezier_path.size() - 1) {
    bezier_index = _bezier_path.size() - 1;
  }
  double relative_progress = relative_duration - bezier_index;   

  return _bezier_path.at(bezier_index).Interpolate(relative_progress);
}
