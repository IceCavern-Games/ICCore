#pragma once
#include <Mesh.h>

#include <glm/glm.hpp>

namespace ICCore {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec3 color;
        glm::vec2 uv;
    };
}
