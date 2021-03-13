#include <iostream>
#include <GLFW/glfw3.h>

#include "main.h"

#define GLM_FORCE_RADIANS

/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods) {
    // Function is called first on GLFW_PRESS.

    if (key == GLFW_KEY_D)
        moveCamera(CAMERA_RIGHT);
    if (key == GLFW_KEY_A)
        moveCamera(CAMERA_LEFT);
    if (key == GLFW_KEY_W)
        moveCamera(CAMERA_UP);
    if (key == GLFW_KEY_S)
        moveCamera(CAMERA_DOWN);
    if (key == GLFW_KEY_E)
        moveCamera(CAMERA_IN);
    if (key == GLFW_KEY_Z)
        moveCamera(CAMERA_OUT);

    if (key == GLFW_KEY_K)
        moveObject(OBJECT_RIGHT);
    if (key == GLFW_KEY_J)
        moveObject(OBJECT_LEFT);
    if (key == GLFW_KEY_I)
        moveObject(OBJECT_UP);
    if (key == GLFW_KEY_M)
        moveObject(OBJECT_DOWN);
    if (key == GLFW_KEY_N)
        moveObject(OBJECT_IN);
    if (key == GLFW_KEY_O)
        moveObject(OBJECT_OUT);


    if (action == GLFW_RELEASE) {

        if (key == GLFW_KEY_R)
            startRotation();

        if (key == GLFW_KEY_T)
            startCameraSpin();

        if (key == GLFW_KEY_F)
            teleport(1);
        else if (key == GLFW_KEY_G)
            teleport(2);
        else if (key == GLFW_KEY_H)
            teleport(3);

    } else if (action == GLFW_PRESS) {

        switch (key) {
            case GLFW_KEY_ESCAPE:
                quit(window);
                break;
            default:
                break;
        }
    }


}

/* Executed for character input (like in text boxes) */
void keyboardChar(GLFWwindow *window, unsigned int key) {
    switch (key) {
        case 'Q':
        case 'q':
            quit(window);
            break;
        default:
            break;
    }
}

/* Executed when a mouse button is pressed/released */
void mouseButton(GLFWwindow *window, int button, int action, int mods) {
    switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            if (action == GLFW_PRESS) {
                // Do something
                return;
            } else if (action == GLFW_RELEASE) {
                // Do something
            }
            break;
            // case GLFW_MOUSE_BUTTON_RIGHT:
            // if (action == GLFW_RELEASE) {
            // rectangle_rot_dir *= -1;
            // }
            // break;
        default:
            break;
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    // Do something
}
