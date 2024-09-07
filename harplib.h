#ifndef HARPLIB_H
#define HARPLIB_H

#include <GLFW/glfw3.h>

#include <stdbool.h>
#include <stdlib.h>

GLFWwindow* setup_window(int width, int height, const char *title);
bool window_is_open(GLFWwindow* window);
void terminate_harplib();
void resize_callback(GLFWwindow* window, int w, int h);

#endif //  HARPLIB_H
