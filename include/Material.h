#pragma once

namespace ICCore {
    enum MaterialPropertyType {
        Texture,
        Float,
        Vec2,
        Vec3,
        Vec4
    };

    struct MaterialProperty {
        MaterialPropertyType propertyType;
    };

    class Material {
    public:
        Material();
        ~Material() = default;
    };
} // namespace ICCore
