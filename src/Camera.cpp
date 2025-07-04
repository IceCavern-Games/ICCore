#include "Camera.h"

namespace ICCore {
    Camera::Camera(ICcore::Window &window, glm::vec3 position, glm::vec3 look, glm::vec3 up)
        : _window(window),
          _up(up),
          _look(look) {
        _right = glm::normalize(glm::cross(_look, _up));
        MoveCamera(position);
    }

    void Camera::MoveCamera(glm::vec3 position) {
        _position = position;
        _view = glm::lookAt(_position, _position + _look, _up);
    }
}