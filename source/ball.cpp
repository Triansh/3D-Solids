#include "ball.h"
#include "main.h"

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ball::tick() {
    this->rotation += isRotating ? speed : 0;
}

void Ball::processKeyBoard(MovementType mt) {
    float velocity = speed * 0.1;
    if (mt == OBJECT_LEFT)
        position -= glm::vec3(1.0f, 0.0f, 0.0f) * velocity;
    if (mt == OBJECT_RIGHT)
        position += glm::vec3(1.0f, 0.0f, 0.0f) * velocity;
    if (mt == OBJECT_UP)
        position += glm::vec3(0.0f, 1.0f, 0.0f) * velocity;
    if (mt == OBJECT_DOWN)
        position -= glm::vec3(0.0f, 1.0f, 0.0f) * velocity;
    if (mt == OBJECT_IN)
        position += glm::vec3(0.0f, 0.0f, 1.0f) * velocity;
    if (mt == OBJECT_OUT)
        position -= glm::vec3(0.0f, 0.0f, 1.0f) * velocity;
}

Ball::Ball(float x, float y, int number) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    isRotating = 0;
    speed = 1;

    if (number == 1) {
        static const GLfloat vertex_buffer_data[] = {
                2, 0, 1,
                1.61803, 1.17557, 1,
                1.61803, 1.17557, -1,

                2, 3.49691e-07, -1,
                1.61803, 1.17557, -1,
                2, 0, 1,

                1.61803, 1.17557, 1,
                0.618034, 1.90211, 1,
                0.618034, 1.90211, -1,

                1.61803, 1.17557, -1,
                0.618034, 1.90211, -1,
                1.61803, 1.17557, 1,

                0.618034, 1.90211, 1,
                -0.618034, 1.90211, 1,
                -0.618035, 1.90211, -1,

                0.618034, 1.90211, -1,
                -0.618035, 1.90211, -1,
                0.618034, 1.90211, 1,

                -0.618034, 1.90211, 1,
                -1.61803, 1.17557, 1,
                -1.61803, 1.17557, -1,

                -0.618035, 1.90211, -1,
                -1.61803, 1.17557, -1,
                -0.618034, 1.90211, 1,

                -1.61803, 1.17557, 1,
                -2, -1.74846e-07, 1,
                -2, -4.76995e-08, -1,

                -1.61803, 1.17557, -1,
                -2, -4.76995e-08, -1,
                -1.61803, 1.17557, 1,

                -2, -1.74846e-07, 1,
                -1.61803, -1.17557, 1,
                -1.61803, -1.17557, -1,

                -2, -4.76995e-08, -1,
                -1.61803, -1.17557, -1,
                -2, -1.74846e-07, 1,

                -1.61803, -1.17557, 1,
                -0.618034, -1.90211, 1,
                -0.618033, -1.90211, -1,

                -1.61803, -1.17557, -1,
                -0.618033, -1.90211, -1,
                -1.61803, -1.17557, 1,

                -0.618034, -1.90211, 1,
                0.618034, -1.90211, 1,
                0.618035, -1.90211, -1,

                -0.618033, -1.90211, -1,
                0.618035, -1.90211, -1,
                -0.618034, -1.90211, 1,

                0.618034, -1.90211, 1,
                1.61803, -1.17557, 1,
                1.61803, -1.17557, -1,

                0.618035, -1.90211, -1,
                1.61803, -1.17557, -1,
                0.618034, -1.90211, 1,

                1.61803, -1.17557, 1,
                2, 0, 1,
                2, 3.49691e-07, -1,

                1.61803, -1.17557, -1,
                2, 3.49691e-07, -1,
                1.61803, -1.17557, 1,

                2, 0, 1,
                1.61803, 1.17557, 1,
                0, 0, 1,

                1.61803, 1.17557, 1,
                0.618034, 1.90211, 1,
                0, 0, 1,

                0.618034, 1.90211, 1,
                -0.618034, 1.90211, 1,
                0, 0, 1,

                -0.618034, 1.90211, 1,
                -1.61803, 1.17557, 1,
                0, 0, 1,

                -1.61803, 1.17557, 1,
                -2, -1.74846e-07, 1,
                0, 0, 1,

                -2, -1.74846e-07, 1,
                -1.61803, -1.17557, 1,
                0, 0, 1,

                -1.61803, -1.17557, 1,
                -0.618034, -1.90211, 1,
                0, 0, 1,

                -0.618034, -1.90211, 1,
                0.618034, -1.90211, 1,
                0, 0, 1,

                0.618034, -1.90211, 1,
                1.61803, -1.17557, 1,
                0, 0, 1,

                1.61803, -1.17557, 1,
                2, 0, 1,
                0, 0, 1,

                2, 3.49691e-07, -1,
                1.61803, 1.17557, -1,
                0, 0, -1,

                1.61803, 1.17557, -1,
                0.618034, 1.90211, -1,
                0, 0, -1,

                0.618034, 1.90211, -1,
                -0.618035, 1.90211, -1,
                0, 0, -1,

                -0.618035, 1.90211, -1,
                -1.61803, 1.17557, -1,
                0, 0, -1,

                -1.61803, 1.17557, -1,
                -2, -4.76995e-08, -1,
                0, 0, -1,

                -2, -4.76995e-08, -1,
                -1.61803, -1.17557, -1,
                0, 0, -1,

                -1.61803, -1.17557, -1,
                -0.618033, -1.90211, -1,
                0, 0, -1,

                -0.618033, -1.90211, -1,
                0.618035, -1.90211, -1,
                0, 0, -1,

                0.618035, -1.90211, -1,
                1.61803, -1.17557, -1,
                0, 0, -1,

                1.61803, -1.17557, -1,
                2, 3.49691e-07, -1,
                0, 0, -1,
        };
        static const GLfloat color_buffer_data[] = {
                0.25, 0.25, 0.5,
                0.25, 0.25, 0.5,
                0.25, 0.25, 0.5,

                0.25, 0.25, 0.5,
                0.25, 0.25, 0.5,
                0.25, 0.25, 0.5,

                0.25, 0.5, 0.75,
                0.25, 0.5, 0.75,
                0.25, 0.5, 0.75,

                0.25, 0.5, 0.75,
                0.25, 0.5, 0.75,
                0.25, 0.5, 0.75,

                0.5, 0.25, 0.5,
                0.5, 0.25, 0.5,
                0.5, 0.25, 0.5,

                0.5, 0.25, 0.5,
                0.5, 0.25, 0.5,
                0.5, 0.25, 0.5,

                0.5, 0.75, 0.25,
                0.5, 0.75, 0.25,
                0.5, 0.75, 0.25,

                0.5, 0.75, 0.25,
                0.5, 0.75, 0.25,
                0.5, 0.75, 0.25,

                0.75, 0.75, 0.75,
                0.75, 0.75, 0.75,
                0.75, 0.75, 0.75,

                0.75, 0.75, 0.75,
                0.75, 0.75, 0.75,
                0.75, 0.75, 0.75,

                0.25, 0.5, 0.25,
                0.25, 0.5, 0.25,
                0.25, 0.5, 0.25,

                0.25, 0.5, 0.25,
                0.25, 0.5, 0.25,
                0.25, 0.5, 0.25,

                0.5, 0.5, 0.75,
                0.5, 0.5, 0.75,
                0.5, 0.5, 0.75,

                0.5, 0.5, 0.75,
                0.5, 0.5, 0.75,
                0.5, 0.5, 0.75,

                0.5, 0.75, 0.5,
                0.5, 0.75, 0.5,
                0.5, 0.75, 0.5,

                0.5, 0.75, 0.5,
                0.5, 0.75, 0.5,
                0.5, 0.75, 0.5,

                0.75, 0.5, 0.5,
                0.75, 0.5, 0.5,
                0.75, 0.5, 0.5,

                0.75, 0.5, 0.5,
                0.75, 0.5, 0.5,
                0.75, 0.5, 0.5,

                0.25, 0.75, 0.5,
                0.25, 0.75, 0.5,
                0.25, 0.75, 0.5,

                0.25, 0.75, 0.5,
                0.25, 0.75, 0.5,
                0.25, 0.75, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
        };
        this->object = create3DObject(GL_TRIANGLES, 40 * 3, vertex_buffer_data, color_buffer_data, GL_FILL);
    } else if (number == 2) {
        static const GLfloat vertex_buffer_data[] = {
                2.5, 0, 0,
                1.25, 2.16506, 0,
                0, 0, -2.5,

                1.25, 2.16506, 0,
                -1.25, 2.16506, 0,
                0, 0, -2.5,

                -1.25, 2.16506, 0,
                -2.5, -2.18557e-07, 0,
                0, 0, -2.5,

                -2.5, -2.18557e-07, 0,
                -1.25, -2.16506, 0,
                0, 0, -2.5,

                -1.25, -2.16506, 0,
                1.25, -2.16506, 0,
                0, 0, -2.5,

                1.25, -2.16506, 0,
                2.5, 0, 0,
                0, 0, -2.5,

                2.5, 0, 0,
                1.25, 2.16506, 0,
                0, 0, 2.5,

                1.25, 2.16506, 0,
                -1.25, 2.16506, 0,
                0, 0, 2.5,

                -1.25, 2.16506, 0,
                -2.5, -2.18557e-07, 0,
                0, 0, 2.5,

                -2.5, -2.18557e-07, 0,
                -1.25, -2.16506, 0,
                0, 0, 2.5,

                -1.25, -2.16506, 0,
                1.25, -2.16506, 0,
                0, 0, 2.5,

                1.25, -2.16506, 0,
                2.5, 0, 0,
                0, 0, 2.5, 2.5, 0, 0,
                1.25, 2.16506, 0,
                0, 0, -2.5,

                1.25, 2.16506, 0,
                -1.25, 2.16506, 0,
                0, 0, -2.5,

                -1.25, 2.16506, 0,
                -2.5, -2.18557e-07, 0,
                0, 0, -2.5,

                -2.5, -2.18557e-07, 0,
                -1.25, -2.16506, 0,
                0, 0, -2.5,

                -1.25, -2.16506, 0,
                1.25, -2.16506, 0,
                0, 0, -2.5,

                1.25, -2.16506, 0,
                2.5, 0, 0,
                0, 0, -2.5,

                2.5, 0, 0,
                1.25, 2.16506, 0,
                0, 0, 2.5,

                1.25, 2.16506, 0,
                -1.25, 2.16506, 0,
                0, 0, 2.5,

                -1.25, 2.16506, 0,
                -2.5, -2.18557e-07, 0,
                0, 0, 2.5,

                -2.5, -2.18557e-07, 0,
                -1.25, -2.16506, 0,
                0, 0, 2.5,

                -1.25, -2.16506, 0,
                1.25, -2.16506, 0,
                0, 0, 2.5,

                1.25, -2.16506, 0,
                2.5, 0, 0,
                0, 0, 2.5,
        };
        static const GLfloat color_buffer_data[] = {
                0.25, 0.25, 0.5,
                0.25, 0.25, 0.5,
                0.25, 0.25, 0.5,

                0.25, 0.5, 0.75,
                0.25, 0.5, 0.75,
                0.25, 0.5, 0.75,

                0.5, 0.25, 0.5,
                0.5, 0.25, 0.5,
                0.5, 0.25, 0.5,

                0.5, 0.75, 0.25,
                0.5, 0.75, 0.25,
                0.5, 0.75, 0.25,

                0.75, 0.75, 0.75,
                0.75, 0.75, 0.75,
                0.75, 0.75, 0.75,

                0.25, 0.5, 0.25,
                0.25, 0.5, 0.25,
                0.25, 0.5, 0.25,

                0.5, 0.5, 0.75,
                0.5, 0.5, 0.75,
                0.5, 0.5, 0.75,

                0.5, 0.75, 0.5,
                0.5, 0.75, 0.5,
                0.5, 0.75, 0.5,

                0.75, 0.5, 0.5,
                0.75, 0.5, 0.5,
                0.75, 0.5, 0.5,

                0.25, 0.75, 0.5,
                0.25, 0.75, 0.5,
                0.25, 0.75, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
        };
        this->object = create3DObject(GL_TRIANGLES, 12 * 3, vertex_buffer_data, color_buffer_data, GL_FILL);
    } else {
        static const GLfloat vertex_buffer_data[] = {
                2.5, 0, 0,
                2.10313, 1.3516, 0,
                0, 0, 2.5,

                2.10313, 1.3516, 0,
                1.03854, 2.27408, 0,
                0, 0, 2.5,

                1.03854, 2.27408, 0,
                -0.355787, 2.47455, 0,
                0, 0, 2.5,

                -0.355787, 2.47455, 0,
                -1.63715, 1.88937, 0,
                0, 0, 2.5,

                -1.63715, 1.88937, 0,
                -2.39873, 0.704332, 0,
                0, 0, 2.5,

                -2.39873, 0.704332, 0,
                -2.39873, -0.704331, 0,
                0, 0, 2.5,

                -2.39873, -0.704331, 0,
                -1.63715, -1.88937, 0,
                0, 0, 2.5,

                -1.63715, -1.88937, 0,
                -0.355788, -2.47455, 0,
                0, 0, 2.5,

                -0.355788, -2.47455, 0,
                1.03854, -2.27408, 0,
                0, 0, 2.5,

                1.03854, -2.27408, 0,
                2.10313, -1.3516, 0,
                0, 0, 2.5,

                2.10313, -1.3516, 0,
                2.5, 0, 0,
                0, 0, 2.5,

                2.5, 0, 0,
                2.10313, 1.3516, 0,
                0, 0, 0,

                2.10313, 1.3516, 0,
                1.03854, 2.27408, 0,
                0, 0, 0,

                1.03854, 2.27408, 0,
                -0.355787, 2.47455, 0,
                0, 0, 0,

                -0.355787, 2.47455, 0,
                -1.63715, 1.88937, 0,
                0, 0, 0,

                -1.63715, 1.88937, 0,
                -2.39873, 0.704332, 0,
                0, 0, 0,

                -2.39873, 0.704332, 0,
                -2.39873, -0.704331, 0,
                0, 0, 0,

                -2.39873, -0.704331, 0,
                -1.63715, -1.88937, 0,
                0, 0, 0,

                -1.63715, -1.88937, 0,
                -0.355788, -2.47455, 0,
                0, 0, 0,

                -0.355788, -2.47455, 0,
                1.03854, -2.27408, 0,
                0, 0, 0,

                1.03854, -2.27408, 0,
                2.10313, -1.3516, 0,
                0, 0, 0,

                2.10313, -1.3516, 0,
                2.5, 0, 0,
                0, 0, 0,
        };
        static const GLfloat color_buffer_data[] = {
                0.25, 0.25, 0.5,
                0.25, 0.25, 0.5,
                0.25, 0.25, 0.5,

                0.25, 0.5, 0.75,
                0.25, 0.5, 0.75,
                0.25, 0.5, 0.75,

                0.5, 0.25, 0.5,
                0.5, 0.25, 0.5,
                0.5, 0.25, 0.5,

                0.5, 0.75, 0.25,
                0.5, 0.75, 0.25,
                0.5, 0.75, 0.25,

                0.75, 0.75, 0.75,
                0.75, 0.75, 0.75,
                0.75, 0.75, 0.75,

                0.25, 0.5, 0.25,
                0.25, 0.5, 0.25,
                0.25, 0.5, 0.25,

                0.5, 0.5, 0.75,
                0.5, 0.5, 0.75,
                0.5, 0.5, 0.75,

                0.5, 0.75, 0.5,
                0.5, 0.75, 0.5,
                0.5, 0.75, 0.5,

                0.75, 0.5, 0.5,
                0.75, 0.5, 0.5,
                0.75, 0.5, 0.5,

                0.25, 0.75, 0.5,
                0.25, 0.75, 0.5,
                0.25, 0.75, 0.5,

                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,
                0.75, 0.25, 0.5,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,

                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
                0.5, 0.25, 0.75,
        };
        this->object = create3DObject(GL_TRIANGLES, 22 * 3, vertex_buffer_data, color_buffer_data, GL_FILL);
    }
}
