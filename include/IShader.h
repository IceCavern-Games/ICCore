#pragma once

#include <glm/glm.hpp>
#include <string>
#include <variant>

namespace ICCore {
    using ShaderProperty = std::variant<bool, int, float, glm::vec2, glm::vec3, glm::vec4, glm::mat4>;

    class IShader {
    public:
        virtual ~IShader() = default;
        virtual void Bind() = 0;
        virtual void SetUniform(std::string name, const ShaderProperty &value) {
            std::visit([&](const auto &v) { SetTypedUniform(name, v); }, value);
        }
        virtual void BindUniformBuffer(const std::string &name, int index) const = 0;

    protected:
        virtual void SetTypedUniform(const std::string &name, bool value) = 0;
        virtual void SetTypedUniform(const std::string &name, int value) = 0;
        virtual void SetTypedUniform(const std::string &name, float value) = 0;
        virtual void SetTypedUniform(const std::string &name, const glm::vec2 &value) = 0;
        virtual void SetTypedUniform(const std::string &name, const glm::vec3 &value) = 0;
        virtual void SetTypedUniform(const std::string &name, const glm::vec4 &value) = 0;
        virtual void SetTypedUniform(const std::string &name, const glm::mat4 &value) = 0;
    };
} // namespace ICCore