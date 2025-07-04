#include "Window.h"

#include <iostream>

namespace ICcore {
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

    void Window::ClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    // @todo: move this into dedicated input manager?
    bool Window::GetKeyDown(const int key) {
        return glfwGetKey(_window, key);
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

        glViewport(0, 0, _width, _height);
        glfwSetFramebufferSizeCallback(_window, FrameBufferSizeCallback);
    }

    void Window::FrameBufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
}
