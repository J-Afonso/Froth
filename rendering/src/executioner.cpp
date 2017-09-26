#include <glad.h>
#include <GLFW/glfw3.h>
#include <cubic_bezier.h>
#include <bezier_animator.h>
#include <bezier_path_renderer.h>

using Eigen::Vector3f;
using bezier::BezierPath;
using bezier::BezierPoint;

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
	GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
    }
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	window = glfwCreateWindow(640, 240, "Bezier", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(1);

	BezierPath path;

	BezierPoint point_1;
	point_1.point = Vector3f(-1, -1, 0);
	point_1.handle_b = Vector3f(-0.4, -1, 0);
	path.Add(point_1);

	BezierPoint point_2;
	point_2.point = Vector3f(0, 1, 0);
	point_2.handle_a = Vector3f(-0.3, 1, 0);
	point_2.handle_b = Vector3f(0.3, 1, 0);
	path.Add(point_2);

	BezierPoint point_3;
	point_3.point = Vector3f(1, -1, 0);
	point_3.handle_a = Vector3f(0.4, -1, 0);
	path.Add(point_3);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	bezier::BezierPathRenderer renderer;
	renderer.setup();

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

        //TODO(j-afonso): I need to find a way to calculate and propagate the frame delta.
        //bezier_animator.tick(1.0f);
        renderer.draw(&path);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}