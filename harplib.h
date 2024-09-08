#ifndef HARPLIB_H
#define HARPLIB_H

#include <GLFW/glfw3.h>

#include <stdbool.h>
#include <stdio.h>

void CreateWindow(int width, int height, const char* title);
void ResizeWindow(int w, int h);
bool WindowShouldClose();
void CloseWindow();
void EndDrawing();
GLFWwindow* GetWindowHandle();


#endif //  HARPLIB_H
