#include <glad.h>
#include <GLFW/glfw3.h>
#include <cubic_bezier.h>
#include <stdlib.h>
#include <stdio.h>

static const char* vertex_shader_text =
	"attribute vec2 vPos;\n"
	"void main(){\n"
	"    gl_Position = vec4(vPos, 0.0, 1.0);\n"
	"}\n";

static const char* fragment_shader_text =	
	"void main(){\n"
	"    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
	"}\n";

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

constexpr int kNumVertices = 1000;

int main(void)
{
	GLFWwindow* window;
	GLuint vertex_buffer, vertex_shader, fragment_shader, program;
	GLint vpos_location;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(640, 480, "Bezier", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(1);

  bezier::CubicBezier cubic_bezier(Vector3f(-1, -1, 0), Vector3f(1, 1, 0), Vector3f(0, -1, 0), Vector3f(0, 1, 0));

	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
	glCompileShader(vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
	glCompileShader(fragment_shader);

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	vpos_location = glGetAttribLocation(program, "vPos");

	glEnableVertexAttribArray(vpos_location);
	glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	int width, height;

	glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, width, height);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glEnable(GL_LINE_SMOOTH);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

	while (!glfwWindowShouldClose(window))
	{		
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(program);

    float vertices[kNumVertices][2];
    for (int i = 0; i < kNumVertices; ++i) {
      const float t = i / (float)kNumVertices;
      Eigen::Vector3f pos = cubic_bezier.Interpolate(t);
      vertices[i][0] = pos.x();
      vertices[i][1] = pos.y();
    }

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		glLineWidth(1);
		glDrawArrays(GL_LINE_STRIP, 0, kNumVertices);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}