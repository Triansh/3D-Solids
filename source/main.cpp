#include "main.h"
#include "timer.h"
#include "ball.h"
#include "camera.h"

using namespace std;

GLMatrices Matrices;
GLuint programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball;
Camera camera;
Timer t60(1.0 / 60);

void draw();
void tick_elements();
void initGL(GLFWwindow *window, int width, int height, int num);
int takeShapeNumber();

int main(int argc, char **argv) {

    srand(time(0));
    int width = 800;
    int height = 600;

    int num = takeShapeNumber();

    window = initGLFW(width, height);

    initGL(window, width, height, num);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) { // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
        }
        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }
    quit(window);
}


/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    glUseProgram(programID);

    Matrices.view = camera.GetViewMatrix();
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    ball.draw(VP);
}


void tick_elements() {
    ball.tick();
    camera.tick(ball.position);
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height, int num) {
    /* Objects should be created before any other gl function and shaders */

    ball = Ball(0, 0, num);
    camera = Camera();

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("../source/shaders/shader.vert", "../source/shaders/shader.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

    reshapeWindow(window, width, height);

    // Background color of the scene
    glClearColor(.9, .9, .9, 0.0f); // R, G, B, A
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int takeShapeNumber() {

    cout << "Choose one among these shapes:\n";
    cout << "1. Decagonal Prism\n";
    cout << "2. Hexagonal Dipyramid\n";
    cout << "3. Undecagonal Pyramid\n";
    cout << "Type the number to choose (If number is not from this range, 3 will be taken): ";

    int number;
    cin >> number;
    return number <= 3 and number >= 1 ? number : 3;

}


void reset_screen() {
    Matrices.projection = glm::perspective(glm::radians(45.0f), (float) 8.0 / 6, 0.1f, 100.0f);
}

void moveCamera(MovementType mt) {
    camera.ProcessKeyboard(mt);
}

void moveObject(MovementType mt) {
    ball.processKeyBoard(mt);
}

void startRotation() {
    ball.isRotating = !ball.isRotating;
}

void startCameraSpin() {
    camera.spin = !camera.spin;
}

void teleport(int num) {
    if (num == 1) {
        camera.Position = glm::vec3(0, 0, 10);
    } else if (num == 2) {
        camera.Position = glm::vec3(5, -5, 5);
    } else if (num == 3) {
        camera.Position = glm::vec3(10, 0, 0);
    } else {
        return;
    }
    camera.recenter(ball.position);
}