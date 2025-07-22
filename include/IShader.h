#pragma once

#include <glm/glm.hpp>
#include <string>
#include <variant>

namespace ICCore {
    using ShaderProperty = std::variant<bool, float, glm::vec2, glm::vec3, glm::vec4, glm::mat4>;

    class IShader {
    public:
        virtual ~IShader() = default;
        virtual void Bind() = 0;
        void SetUniform(std::string name, const ShaderProperty &value);

    protected:
        virtual void SetTypedUniform(std::string name, bool value);
        virtual void SetTypedUniform(std::string name, float value);
        virtual void SetTypedUniform(std::string name, glm::vec2 &value);
        virtual void SetTypedUniform(std::string name, glm::vec3 &value);
        virtual void SetTypedUniform(std::string name, glm::vec4 &value);
        virtual void SetTypedUniform(std::string name, glm::mat4 &value);
    };
} // namespace ICCore