#include "bezier_path.h"

void bezier::BezierPath::Add(const bezier::BezierPoint &point) {
  _points.push_back(point);
  _dirty = true;
}

Vector3f bezier::BezierPath::Get(const float t) {
  if(_dirty){
    // Recalculate the path.
    _bezier_path.clear();
    const BezierPoint* previous_point = NULL;
    for (const BezierPoint point : _points) {
      if(previous_point != NULL) {
        // TODO(j-afonso): CHECK IF ALL THE HANDLES ARE FILLED UP.
        CubicBezier bezier(previous_point->point, point.point, previous_point->handle_b,
                           point.handle_a);
        _bezier_path.push_back(bezier);
      }
      previous_point = &point;
    }
    _dirty = false;
  }





  return Eigen::Vector3f();
}
