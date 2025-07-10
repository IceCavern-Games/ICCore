#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.h"

namespace ICCore {
    class Camera {
    public:
        glm::mat4 &GetViewMatrix() { return _view; }
        glm::mat4 &GetProjectionMatrix() { return _projection; }

        Camera(Window &window, glm::vec3 position, glm::vec3 up = {0.0f, 1.0f, 0.0f},
               glm::vec3 look = {0.0f, 0.0f, -1.0f});

        void MoveCamera(glm::vec3 position);

        void SetAspectRatio(float aspectRatio);

    private:
        Window &_window;

        glm::mat4 _view;
        glm::mat4 _projection;

        glm::vec3 _position;
        glm::vec3 _right;
        glm::vec3 _up;
        glm::vec3 _look;

        float _fieldOfView = glm::radians(45.0f);
        float _aspectRatio = 16.0f / 9.0f;
        float _nearPlane = 0.01f;
        float _farPlane = 1000.0f;

        void UpdateProjectionMatrix();
    };
}
