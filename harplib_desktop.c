#include "harplib.h"

typedef struct {
    GLFWwindow *handle;                 // GLFW window handle
} WindowHandler;

WindowHandler window = {0};

void CreateWindow(int width, int height, const char* title) {
    if(!glfwInit()) {
        printf("Could not initialize GLFW");
	return;
    }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window.handle = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!window.handle) {
		glfwTerminate();
       	 	printf("Could not create window");
		return
	}

	glfwMakeContextCurrent(window.handle);

	glViewport(0, 0, width, height);
}

void ResizeWindow(int w, int h) {
	glViewport(0, 0, w, h);
}

bool WindowShouldClose() {
	return glfwWindowShouldClose(window.handle);
}

void CloseWindow() {
    glfwDestroyWindow(window.handle);
	glfwTerminate();
}

GLFWwindow* GetWindowHandle(){
    return window.handle;
}
