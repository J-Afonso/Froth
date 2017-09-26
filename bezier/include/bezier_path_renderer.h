#ifndef BEZIER_CUBIC_BEZIER_RENDERER_H
#define BEZIER_CUBIC_BEZIER_RENDERER_H

#include <bezier_path.h>
#include <glad.h>

namespace bezier {
    class BezierPathRenderer {
        public:
            void setup();
            void draw(bezier::BezierPath*);

    private:
        GLuint _vertex_buffer;
        GLuint _program;
    };
} // namespace bezier
#endif //BEZIER_CUBIC_BEZIER_RENDERER_H
