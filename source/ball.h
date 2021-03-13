#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y, int number);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void processKeyBoard(MovementType mt);
    void tick();
    float speed;
    int isRotating ;

protected:
    VAO *object;
};

#endif // BALL_H
