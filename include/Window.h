#pragma once

#include <string>

#include <GLFW/glfw3.h>

namespace ICcore {
    class Window {
    public:
        Window(int width, int height, const std::string &title);
        ~Window();

        bool ShouldClose() const;
        void ClearColor(float r, float g, float b, float a);
        bool GetKeyDown(int key);
        float GetDeltaTime() { return _deltaTime; }
        GLFWwindow *GetGLFWwindow() { return _window; }
        void ProcessInput();
        void SwapBuffers() const;

    private:
        int _height, _width;
        std::string _title;
        float _deltaTime = 0.0f;
        float _lastFrameTime = 0.0f;

        GLFWwindow *_window;

        static void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);

        void Init();
    };
}
