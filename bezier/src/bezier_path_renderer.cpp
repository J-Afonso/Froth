#include "bezier_path_renderer.h"

namespace bezier {

    static const char* kVertexShader =
            "attribute vec2 vPos;\n"
                    "void main(){\n"
                    "    gl_Position = vec4(vPos, 0.0, 1.0);\n"
                    "}\n";

    static const char* kFragmentShader =
            "void main(){\n"
                    "    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
                    "}\n";

    constexpr int kNumVertices = 1000;

    void BezierPathRenderer::setup() {
        GLuint vertex_shader, fragment_shader;
        GLint vpos_location;

        glGenBuffers(1, &_vertex_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &kVertexShader, NULL);
        glCompileShader(vertex_shader);

        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &kFragmentShader, NULL);
        glCompileShader(fragment_shader);

        _program = glCreateProgram();
        glAttachShader(_program, vertex_shader);
        glAttachShader(_program, fragment_shader);
        glLinkProgram(_program);

        vpos_location = glGetAttribLocation(_program, "vPos");

        glEnableVertexAttribArray(vpos_location);
        glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE, 0, (void*) 0);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    }

    void BezierPathRenderer::draw(bezier::BezierPath* bezier_path){
        // CHECK_NOT_NULL(bezier_path);
        glUseProgram(_program);

        float vertices[kNumVertices][2];
        for (int i = 0; i < kNumVertices; ++i) {
            const float t = i / (float)kNumVertices;
            Eigen::Vector3f pos = bezier_path->Get(t);
            vertices[i][0] = pos[0];
            vertices[i][1] = pos[1];
        }

        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

        glLineWidth(1);
        glDrawArrays(GL_LINE_STRIP, 0, kNumVertices);
    }

} // namespace bezier