#pragma once
#include "IShader.h"

namespace ICCore {
    class Material {
    public:
        Material(IShader &shader);
        ~Material() = default;

        IShader &GetShader() const { return _shader; }

    private:
        IShader &_shader;
    };
} // namespace ICCore
