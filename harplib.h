#ifndef HARPLIB_H
#define HARPLIB_H

#include <GLFW/glfw3.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// structs for objects
typedef struct {
    float x;
    float y;
    float z;
} Position;

typedef struct {
    Position position;
    unsigned int shader_id;
} GameObject;

void SetObjectShader(GameObject* object, const char* vertex_shader, char* fragment_shader);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void CreateWindow(int width, int height, const char* title);
void ResizeWindow(int w, int h);
bool WindowShouldClose();
void CloseWindow();
void DrawScreen();
GLFWwindow* GetWindowHandle();


#endif //  HARPLIB_H
