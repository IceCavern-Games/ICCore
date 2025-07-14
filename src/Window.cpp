#include "Window.h"

#include <iostream>

namespace ICCore {
    Window::Window(const int width, const int height, const std::string &title) {
        _height = height;
        _width = width;
        _title = title;

        Init();
    }

    Window::~Window() {}

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(_window);
    }

    // @todo: move this into dedicated input manager?
    bool Window::GetKeyDown(const int key) {
        return glfwGetKey(_window, key);
    }

    bool Window::GetMouseDown(const int button) {
        return glfwGetMouseButton(_window, button);
    }

    void Window::ProcessInput() {
        float currentFrameTime = glfwGetTime();
        _deltaTime = currentFrameTime - _lastFrameTime;
        _lastFrameTime = currentFrameTime;
    }

    void Window::SwapBuffers() const {
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    void Window::Init() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        _window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);

        if (_window == nullptr) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }

        glfwMakeContextCurrent(_window);

        glfwSetFramebufferSizeCallback(_window, FrameBufferSizeCallback);
    }

    void Window::FrameBufferSizeCallback(GLFWwindow *window, int width, int height) {}
} // namespace ICCore
