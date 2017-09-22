#include <glad.h>
#include <GLFW/glfw3.h>
#include <cubic_bezier.h>
#include <bezier_animator.h>
#include <cubic_bezier_renderer.h>

using Eigen::Vector3f;
using bezier::CubicBezier;
using bezier::BezierAnimator;

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

	window = glfwCreateWindow(640, 480, "Bezier", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(1);

    CubicBezier start(Vector3f(-1, -1, 0), Vector3f(1, 1, 0), Vector3f(0, -1, 0), Vector3f(0, 1, 0));
    CubicBezier end(Vector3f(-1, 1, 0), Vector3f(1, -1, 0), Vector3f(-1, 0, 0), Vector3f(1, 0, 0));

    BezierAnimator bezier_animator(start, end, 1000);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

    bezier::CubicBezierRenderer renderer;
    renderer.setup();

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

        //TODO(j-afonso): I need to find a way to calculate and propagate the frame delta.
        bezier_animator.tick(1.0f);

        CubicBezier cubic_bezier = bezier_animator.get();
        renderer.draw(cubic_bezier);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}