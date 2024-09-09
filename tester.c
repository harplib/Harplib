//
// Created by Michael Reyes on 9/7/24.
//
#include "harplib.h"

int main(){
    int width = 640;
    int height = 480;

    CreateWindow(width, height, "tester");
    //Loop until the program is quit
    while (!WindowShouldClose())
    {
        //2D Mode

        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

        glOrtho(0 , width , height , 0 , 0 , 1);

        glDisable(GL_DEPTH_TEST);

        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();

        glClearColor(0.5f, 0.125f, 0.125f, 0);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(GetWindowHandle());
        glfwSwapInterval(1);
        glfwPollEvents();
    }
    CloseWindow();
    return 0;
}