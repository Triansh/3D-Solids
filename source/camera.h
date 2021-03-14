#ifndef INC_3DSHAPES_CAMERA_H
#define INC_3DSHAPES_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "main.h"

// An abstract camera class that processes input and
// calculates the corresponding Vectors and Matrices for use in OpenGL
class Camera {
public:
    // camera Attributes
    int spin;
    float rotation;
    float speed;
    glm::vec3 axes;

    // Camera coordinate and position Vector
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    // constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f)) {
        Position = position;
        WorldUp = up;
        spin = 0;
        rotation = 1;
        speed = 2.5f;
        Front = glm::vec3(0.0f, 0.0f, -1.0f);
        updateCameraVectors();
    }

    // returns the view matrix calculated using the LookAt Matrix
    glm::mat4 GetViewMatrix() const {
        return glm::lookAt(Position, Position + Front, Up);
    }

    void tick(glm::vec3 target) {
        UpdateSpinning(target);
    }

    // processes input received from any keyboard-like input system.
    // Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(MovementType direction, float deltaTime = 1.0 / 10) {
        float velocity = speed * deltaTime;
        if (direction == CAMERA_IN)
            Position += Front * velocity;
        if (direction == CAMERA_OUT)
            Position -= Front * velocity;
        if (direction == CAMERA_LEFT)
            Position -= Right * velocity;
        if (direction == CAMERA_RIGHT)
            Position += Right * velocity;
        if (direction == CAMERA_UP)
            Position += Up * velocity;
        if (direction == CAMERA_DOWN)
            Position -= Up * velocity;
    }

    // This is basically used in teleport.
    // Positions the coordinate system, such that camera faces the target
    void recenter(glm::vec3 target) {
        Front = glm::normalize(target - Position);
        updateCameraVectors();
        axes = Up;
    }

private:

    // Executed while camera is spinning around one of target's axis
    // Based on the principle of shifting of origin
    void UpdateSpinning(glm::vec3 target) {
        if (!spin) return;
//        glm::vec3 axis = (glm::normalize(glm::cross( Front, Right)));
        glm::mat4 t1 = glm::translate(-target);
        glm::mat4 rotateMatrix = glm::rotate(glm::radians(rotation), axes);
        glm::mat4 t2 = glm::translate(target);
        Position = glm::vec3(t2 * rotateMatrix * t1 * glm::vec4(Position, 1));
        Front = glm::normalize(target - Position);
        updateCameraVectors();
    }

    void updateCameraVectors() {
        // re-calculate the Right and Up vector
        // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Right = glm::normalize(glm::cross(Front, WorldUp));
        Up = glm::normalize(glm::cross(Right, Front));
    }
};

#endif