#include "harplib.h"

GLFWwindow* setup_window(int width, int height, const char* title) {
    GLFWwindow* window;
    if(!glfwInit()) {
        return NULL;
    }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!window) {
		glfwTerminate();
		return NULL;
	}

	glfwMakeContextCurrent(window);

	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(window, resize_callback);

	return window;
}

void resize_callback(GLFWwindow* window, int w, int h) {
	glViewport(0, 0, w, h);
}

bool window_is_open(GLFWwindow* window) {
	return !glfwWindowShouldClose(window);
}

void terminate_harplib() {
	glfwTerminate();
}

