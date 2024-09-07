//
// Created by Michael Reyes on 9/7/24.
//
#include "harplib.h"

int main(){
    GLFWwindow* window = setup_window(1280, 720, "title");
    glClearColor( 0.4f, 0.3f, 0.4f, 0.0f );

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        //2D Mode

        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

        glOrtho(0 , 1280 , 720 , 0 , 0 , 1);

        glDisable(GL_DEPTH_TEST);

        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();

        glClearColor(0.5f, 0.125f, 0.125f, 0);

        glClear(GL_COLOR_BUFFER_BIT);

        glColor4f(0.5f, 0.125f, 0.125f, 0);

        glfwSwapBuffers(window);
        glfwSwapInterval(1);
        glfwPollEvents();
    }
    terminate_harplib();
}