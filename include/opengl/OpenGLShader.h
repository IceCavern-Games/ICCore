#pragma once
#include "IShader.h"
#include "glad/glad.h"

namespace ICCore {
    class OpenGLShader : public IShader {
    public:
        OpenGLShader(const char *vertexPath, const char *fragmentPath);
        ~OpenGLShader() override = default;

        void Bind() override;
        void BindUniformBuffer(const std::string &name, int index) const override;

    private:
        unsigned int _id;

        void SetTypedUniform(const std::string &name, bool value) override;
        void SetTypedUniform(const std::string &name, int value) override;
        void SetTypedUniform(const std::string &name, float value) override;
        void SetTypedUniform(const std::string &name, const glm::vec2 &value) override;
        void SetTypedUniform(const std::string &name, const glm::vec3 &value) override;
        void SetTypedUniform(const std::string &name, const glm::vec4 &value) override;
        void SetTypedUniform(const std::string &name, const glm::mat4 &value) override;

        static unsigned int CompileShader(const std::string &filePath, GLenum shaderType);
        static void CheckCompileErrors(unsigned int shader, const std::string &type);
    };
} // namespace ICCore
