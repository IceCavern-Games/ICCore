#include "Camera.h"

namespace ICCore {
    Camera::Camera(Window &window, glm::vec3 position, glm::vec3 up, glm::vec3 look)
        : _window(window),
          _up(up),
          _look(look) {
        _right = glm::normalize(glm::cross(_look, _up));
        _aspectRatio = static_cast<float>(window.Width()) / static_cast<float>(window.Height());
        MoveCamera(position);
        UpdateProjectionMatrix();
    }

    void Camera::MoveCamera(glm::vec3 position) {
        _position = position;
        _view = glm::lookAt(_position, _position + _look, _up);
    }

    void Camera::SetAspectRatio(const float aspectRatio) {
        _aspectRatio = aspectRatio;
        UpdateProjectionMatrix();
    }


    void Camera::UpdateProjectionMatrix() {
        _projection = glm::perspective(_fieldOfView, _aspectRatio, _nearPlane,
                                       _farPlane);
    }

}