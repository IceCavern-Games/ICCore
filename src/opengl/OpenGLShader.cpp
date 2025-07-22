#include "opengl/OpenGLShader.h"

#include "Logger.h"

#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>

namespace ICCore {
    OpenGLShader::OpenGLShader(const char *vertexPath, const char *fragmentPath) {
        unsigned int vertexShader = CompileShader(vertexPath, GL_VERTEX_SHADER);
        unsigned int fragmentShader = CompileShader(fragmentPath, GL_FRAGMENT_SHADER);

        _id = glCreateProgram();
        glAttachShader(_id, vertexShader);
        glAttachShader(_id, fragmentShader);
        glLinkProgram(_id);
        CheckCompileErrors(_id, std::string("PROGRAM"));
    }

    void OpenGLShader::Bind() {
        glUseProgram(_id);
    }

    void OpenGLShader::BindUniformBuffer(const std::string &name, int index) const {
        glUniformBlockBinding(_id, glGetUniformBlockIndex(_id, name.c_str()), index);
    }

    void OpenGLShader::SetTypedUniform(const std::string &name, const bool value) {
        glUniform1i(glGetUniformLocation(_id, name.c_str()), static_cast<int>(value));
    }

    void OpenGLShader::SetTypedUniform(const std::string &name, const int value) {
        glUniform1i(glGetUniformLocation(_id, name.c_str()), value);
    }

    void OpenGLShader::SetTypedUniform(const std::string &name, const float value) {
        glUniform1f(glGetUniformLocation(_id, name.c_str()), value);
    }

    void OpenGLShader::SetTypedUniform(const std::string &name, const glm::vec2 &value) {
        glUniform2f(glGetUniformLocation(_id, name.c_str()), value.x, value.y);
    }

    void OpenGLShader::SetTypedUniform(const std::string &name, const glm::vec3 &value) {
        glUniform3f(glGetUniformLocation(_id, name.c_str()), value.x, value.y, value.z);
    }

    void OpenGLShader::SetTypedUniform(const std::string &name, const glm::vec4 &value) {
        glUniform4f(glGetUniformLocation(_id, name.c_str()), value.x, value.y, value.z, value.w);
    }

    void OpenGLShader::SetTypedUniform(const std::string &name, const glm::mat4 &value) {
        glUniformMatrix4fv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }

    unsigned int OpenGLShader::CompileShader(const std::string &filePath, GLenum shaderType) {
        std::string shaderCode;
        std::ifstream shaderFile;

        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try {
            shaderFile.open(filePath);
            std::stringstream shaderStream;

            shaderStream << shaderFile.rdbuf();

            shaderFile.close();
            shaderCode = shaderStream.str();
        } catch (std::ifstream::failure &e) {
            IC_CORE_ERROR("ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ\n{0}", e.what());
        }

        const char *shaderCodeChar = shaderCode.c_str();

        // compile shader
        unsigned int shader;
        shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &shaderCodeChar, nullptr);
        glCompileShader(shader);
        CheckCompileErrors(shader, "SHADER");

        return shader;
    }

    void OpenGLShader::CheckCompileErrors(const unsigned int shader, const std::string &type) {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM") {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                IC_CORE_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n{0}", infoLog);
            }
        } else {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
                IC_CORE_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n{0}", infoLog);
            }
        }
    }

} // namespace ICCore