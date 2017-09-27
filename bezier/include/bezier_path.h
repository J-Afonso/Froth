#ifndef BEZIER_PATH_H
#define BEZIER_PATH_H
#include <Eigen/Core>
#include <vector>
#include "cubic_bezier.h"

using Eigen::Vector3f;

namespace bezier {
  struct BezierPoint {
    Vector3f point;
    Vector3f handle_a;
    Vector3f handle_b;
  };
  class BezierPath {
    public:
      void Add(const BezierPoint &point);
      Vector3f Get(float);
      void Clear();
      std::vector<BezierPoint> Points() const;

  private:
      std::vector<BezierPoint> _points;
      std::vector<CubicBezier> _bezier_path;
      bool _dirty = false;
  };

} // namespace bezier
#endif //BEZIER_PATH_H

