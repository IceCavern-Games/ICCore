#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Window.h"

namespace ICCore {
    class Camera {
    public:
        glm::mat4 GetViewMatrix() { return _view; }

        Camera(ICcore::Window &window, glm::vec3 position, glm::vec3 up = {0.0f, 1.0f, 0.0f},
               glm::vec3 look = {0.0f, 0.0f, 1.0f});

        void MoveCamera(glm::vec3 position);

    private:
        ICcore::Window &_window;

        glm::mat4 _view;
        glm::vec3 _position;
        glm::vec3 _right;
        glm::vec3 _up;
        glm::vec3 _look;
    };
}
