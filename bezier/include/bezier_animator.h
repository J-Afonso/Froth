#ifndef BEZIER_ANIMATOR_H
#define BEZIER_ANIMATOR_H
#include <Eigen/Core>
#include "cubic_bezier.h"

using Eigen::Vector3f;
using bezier::CubicBezier;

namespace bezier {
  class BezierAnimator {
  public:
    BezierAnimator(const CubicBezier &start, const CubicBezier &end, const float duration) : 
      _start(start), _end(end), _duration(duration), _current(start) {      
    };
    CubicBezier get() const;
    void tick(const float);
  private:
    const CubicBezier _start;
    const CubicBezier _end;
    CubicBezier _current;
    const float _duration;
    float _current_time;
  };
} // namespace bezier
#endif //BEZIER_ANIMATOR_H

