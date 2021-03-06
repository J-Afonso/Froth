#ifndef BEZIER_PATH_ANIMATOR_H
#define BEZIER_PATH_ANIMATOR_H
#include <Eigen/Core>
#include "bezier_path.h"

using Eigen::Vector3f;
using bezier::BezierPath;

namespace bezier {
  class BezierPathAnimator {
  public:
    BezierPathAnimator(const BezierPath &start, const BezierPath &end, float duration);
    BezierPath Get() const;
    void Tick(float);
  private:
    const BezierPath _start;
    const BezierPath _end;
    BezierPath _current;
    const float _duration;
    float _current_time = 0;
  };
} // namespace bezier
#endif //BEZIER_PATH_ANIMATOR_H

