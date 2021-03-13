#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void processKeyBoard(MovementType mt);
    void set_position(float x, float y);
    void tick();
    double speed;
    int isRotating ;
protected:
    VAO *object;
};

class Shape1 : public Ball{

};

#endif // BALL_H
