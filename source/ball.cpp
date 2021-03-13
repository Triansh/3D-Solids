#include "ball.h"
#include "main.h"


Ball::Ball(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    isRotating = 0;
    speed = 1;

//        this->object = create3DObject(GL_TRIANGLES,
//                                      sizeof(vertex_buffer_data) / sizeof(vertex_buffer_data[0]),
//                                      sizeof(indices) / sizeof(indices[0]),
//                                      vertex_buffer_data, indices, GL_FILL);

    static const GLfloat vertex_buffer_data[] = {
            -1.0f,-1.0f,-1.0f, // triangle 1 : begin
            -1.0f,-1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f, // triangle 1 : end
            1.0f, 1.0f,-1.0f, // triangle 2 : begin
            -1.0f,-1.0f,-1.0f,e
            -1.0f, 1.0f,-1.0f, // triangle 2 : end
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f
    };
    this->object = create3DObject(GL_TRIANGLES, 12 * 3, vertex_buffer_data, color, GL_FILL);

//        this->object = create3DObject(GL_TRIANGLES,
//                                      sizeof(vertex_buffer_data) / sizeof(vertex_buffer_data[0]),
//                                      sizeof(indices) / sizeof(indices[0]),
//                                      vertex_buffer_data, indices, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate(this->position);    // glTranslatef
    glm::mat4 rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
    this->rotation += isRotating ? speed : 0;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

void Ball::processKeyBoard(MovementType mt) {
    float velocity = .1f;
    if (mt == OBJECT_LEFT)
        position -= glm::vec3(1.0f, 0.0f, 0.0f) * velocity;
    if (mt == OBJECT_RIGHT) {
        position += glm::vec3(1.0f, 0.0f, 0.0f) * velocity;
    }
    if (mt == OBJECT_UP) {
        position += glm::vec3(0.0f, 1.0f, 0.0f) * velocity;
    }
    if (mt == OBJECT_DOWN) {
        position -= glm::vec3(0.0f, 1.0f, 0.0f) * velocity;
    }
    if (mt == OBJECT_IN) {
        position += glm::vec3(0.0f, 0.0f, 1.0f) * velocity;
    }
    if (mt == OBJECT_OUT) {
        position -= glm::vec3(0.0f, 0.0f, 1.0f) * velocity;
    }
}

