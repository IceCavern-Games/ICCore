#pragma once

#include <string>

#include <opengl/GLHeader.h>

namespace ICCore {
    class Window {
    public:
        Window(int width, int height, const std::string &title);

        ~Window();

        int Width() const { return _width; }
        int Height() const { return _height; }

        bool ShouldClose() const;

        bool GetKeyDown(int key);
        bool GetMouseDown(int button);

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

        static void FrameBufferSizeCallback(GLFWwindow *window, int width, int height);

        void Init();
    };
} // namespace ICCore
