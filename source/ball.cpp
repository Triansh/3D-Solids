#include "ball.h"
#include "main.h"

Ball::Ball(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
            -1.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,   // top upper left
            1.0f, 1.0f, 1.0f,   0.0f, 1.0f, 0.0f,   // top upper right
            -1.0f,-1.0f, 1.0f,  0.0f, 1.0f, 1.0f,   // top down left
            1.0f,-1.0f, 1.0f,   1.0f, 0.0f, 0.0f,   // top down right

            -1.0f, 1.0f,-1.0f,  1.0f, 0.0f, 1.0f,   // bottom upper left
            1.0f, 1.0f,-1.0f,   1.0f, 1.0f, 0.0f,   // bottom upper right
            -1.0f,-1.0f,-1.0f,  0.0f, 0.0f, 1.0f,   // bottom down left
            1.0f,-1.0f,-1.0f,   1.0f, 0.0f, 1.0f,   // bottom down right
    };
     unsigned int indices[] = {
            0, 1, 2,  // top face
            1, 2, 3,

            4, 5, 6,  // bottom face
            5, 6, 7,

            2, 3, 6, // front face
            6, 7, 3,

            0,1, 4, // back face
            4, 5, 1,

            0, 2, 4, // left face
            4, 6, 2,

            1, 3, 5, // right face
            5, 7, 3,
    };

    this->object = create3DObject(GL_TRIANGLES,
                                  sizeof(vertex_buffer_data)/sizeof(vertex_buffer_data[0]),
                                  sizeof(indices)/sizeof(indices[0]),
                                  vertex_buffer_data, indices, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
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
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

