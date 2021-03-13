#ifndef INC_3DSHAPES_CAMERA_H
#define INC_3DSHAPES_CAMERA_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "main.h"

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera {
public:
    // camera Attributes
    int spin;
    float rotation;

    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    glm::vec3 target;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // constructor with vectors
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
           float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, 10.0f)), MovementSpeed(SPEED),
                                                   MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        target = glm::vec3(0, 0, 0);
        spin = 0;
        rotation = 1.0;
        updateCameraVectors();
    }

    // constructor with scalar values
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(
            glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
        Position = glm::vec3(posX, posY, posZ);
        WorldUp = glm::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    glm::mat4 GetViewMatrix() const {
        return glm::lookAt(Position, target, Up);
    }

//    glm::mat4 GetViewMatrix(glm::vec3 target) const {
//        return glm::lookAt(Position, target, Up);
//    }

    void UpdateSpinning(glm::vec3 ballpos) {
        if (!spin) return;
//        float radius = glm::distance(target, Position);
//        Pitch += .1;
//        Yaw += .1;

//        Position.x = target.x + radius * cos(Yaw) * sin(Pitch);
//        Position.y = target.y + radius * sin(Yaw) * sin(Pitch);
//        Position.z = target.x + radius * cos(Pitch);
//        updateCameraVectors();
//        rotation += .1;
//        float mag = glm::distance(target, Position);
        target = ballpos;
        glm::vec3 axis = (glm::normalize(glm::cross(ballpos - Position, Right)));
//        std::cout << Position.x << " " << Position.y << " " << Position.z << "\n";
//        glm::mat4 t1 = glm::translate(vx);
//         rotateMatrix = glm::mat4(1);
        glm::mat4 t1 = glm::translate(ballpos );
        glm::mat4 rotateMatrix = glm::rotate(glm::radians(rotation), glm::vec3(t1 * glm::vec4(axis, 1)));
//        glm::mat4 t2 = glm::translate(axis - ballpos);
//        glm::mat4 t2 = glm::translate(-vx);
        Front = glm::normalize(ballpos - Position);
        Position = glm::vec3(rotateMatrix * glm::vec4(Position, 1));
        std::cout << Position.x << " " << Position.y << " " << Position.z << "\n";
        updateCameraVectors(false);
    }

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(MovementType direction, float deltaTime = 1.0 / 50) {
        float velocity = MovementSpeed * deltaTime;
        if (direction == CAMERA_IN) {
            target += Front * velocity;
            Position += Front * velocity;
        }
        if (direction == CAMERA_OUT) {
            target -= Front * velocity;
            Position -= Front * velocity;
        }
        if (direction == CAMERA_LEFT) {
            target -= Right * velocity;
            Position -= Right * velocity;
        }
        if (direction == CAMERA_RIGHT) {
            target += Right * velocity;
            Position += Right * velocity;
        }
        if (direction == CAMERA_UP) {
            target += Up * velocity;
            Position += Up * velocity;
        }
        if (direction == CAMERA_DOWN) {
            target -= Up * velocity;
            Position -= Up * velocity;
        }


//        if (direction == CAMERA_IN) {
//            target += glm::vec3(0,0,1) * velocity;
//            Position += glm::vec3(0,0,1) * velocity;
//        }
//        if (direction == CAMERA_OUT) {
//            target -= glm::vec3(0,0,1) * velocity;
//            Position -= glm::vec3(0,0,1) * velocity;
//        }
//        if (direction == CAMERA_LEFT) {
//            target -= glm::vec3(1,0,0) * velocity;
//            Position -= glm::vec3(1,0,0) * velocity;
//        }
//        if (direction == CAMERA_RIGHT) {
//            target += glm::vec3(1,0,0) * velocity;
//            Position += glm::vec3(1,0,0) * velocity;
//        }
//        if (direction == CAMERA_UP) {
//            target += glm::vec3(0,1,0) * velocity;
//            Position += glm::vec3(0,1,0) * velocity;
//        }
//        if (direction == CAMERA_DOWN) {
//            target -= glm::vec3(0,1,0) * velocity;
//            Position -= glm::vec3(0,1,0) * velocity;
//        }
    }

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true) {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch) {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset) {
        Zoom -= (float) yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }

    void tick(glm::vec3 target) {
        UpdateSpinning(target);
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors(bool fr = true) {
        // calculate the new Front vector
//        if (fr) {
//            glm::vec3 front;
//            front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
//            front.y = sin(glm::radians(Pitch));
//            front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
//            Front = front;
//        }
//        // also re-calculate the Right and Up vector
        Right = glm::normalize(glm::cross(Front,
                                          WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up = glm::normalize(glm::cross(Right, Front));
    }
};

#endif