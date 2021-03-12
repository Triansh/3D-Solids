#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.h"

bool cannon_keyboard_input = true;
bool drag_pan = false, old_cki;
double drag_oldx = -1, drag_oldy = -1;

using namespace std;

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
        cout << key << " 1\n";

        if (key == GLFW_KEY_R)
            startRotation();

    } else if (action == GLFW_PRESS) {
        cout << key << " 2\n";

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
//    cout << key << " 2\n";
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
