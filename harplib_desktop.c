#include "harplib.h"

typedef struct {
    GLFWwindow *handle;                 // GLFW window handle
} WindowHandler;

WindowHandler window = {0};

// square vertices and indices (for 2D sprites)
float square_vertices[] = {
	-1.0f, 1.0f, 1.0f,
	 1.0f, 1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	 1.0f,-1.0f, 1.0f
};

unsigned int square_indices[] = {
	3,1,2,
	2,4,3
};

char* read_shader_file(const char* filename) {
	FILE* file;
	if (fopen_s(&file, filename, "r") != 0 || !file) {
		return NULL;
	}

	if (fseek(file, 0, SEEK_END) != 0) {
		fclose(file);
		return NULL;
	}

	long length = ftell(file);
	if (length < 0) {
		fclose(file);
		return NULL;
	}

	if (fseek(file, 0, SEEK_SET) != 0) {
		fclose(file);
		return NULL;
	}

	char* buffer = (char*)malloc(length + 1);
	if (!buffer) {
		fclose(file);
		return NULL;
	}

	size_t read_length = fread(buffer, 1, length, file);
	if (read_length != (size_t)length) {
		free(buffer);
		fclose(file);
		return NULL;
	}

	buffer[length] = '\0';

	fclose(file);
	return buffer;
}

void SetObjectShader(GameObject* object, const char* vertex_shader, const char* fragment_shader) {
	int success;
	char info[512];

	char* vertex_shader_code = read_shader_file(vertex_shader);
	if (!vertex_shader_code) {
		return;
	}
	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, (const char**)&vertex_shader_code, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertex, 512, NULL, info);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", info);
	}
	free(vertex_shader_code);

	char* fragment_shader_code = read_shader_file(fragment_shader);
	if (!fragment_shader_code) {
		return;
	}
	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, (const char**)&fragment_shader_code, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragment, 512, NULL, info);
		printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", info);
	}
	free(fragment_shader_code);

	object->shader_id = glCreateProgram();
	glAttachShader(object->shader_id, vertex);
	glAttachShader(object->shader_id, fragment);
	glLinkProgram(object->shader_id);

	glGetProgramiv(object->shader_id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(object->shader_id, 512, NULL, info);
		printf("ERROR::PROGRAM::LINKING_FAILED\n%s\n", info);
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

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
		return;
	}

	glfwMakeContextCurrent(window.handle);

	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(window.handle, framebuffer_size_callback);
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

void DrawScreen() {
	glfwPollEvents();
	glfwSwapBuffers(window.handle);
}

GLFWwindow* GetWindowHandle(){
    return window.handle;
}
