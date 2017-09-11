#ifndef BEZIER_CUBIC_BEZIER_RENDERER_H
#define BEZIER_CUBIC_BEZIER_RENDERER_H

#include <cubic_bezier.h>
#include <glad.h>

namespace bezier {
    class CubicBezierRenderer {
        public:
            void setup();
            void draw(const bezier::CubicBezier&);

    private:
        GLuint _vertex_buffer;
        GLuint _program;
    };
} // namespace bezier
#endif //BEZIER_CUBIC_BEZIER_RENDERER_H
