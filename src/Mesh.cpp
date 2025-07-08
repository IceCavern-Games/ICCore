#include <Mesh.h>

namespace ICCore {
    Mesh::Mesh() {

    }

    void Mesh::SetIndices(const std::vector<uint32_t> &indices) {
        _indices = std::make_unique<std::vector<uint32_t> >(indices);
    }

    void Mesh::SetVertices(const std::vector<Vertex> &vertices) {
        _vertices = std::make_unique<std::vector<Vertex> >(vertices);
    }

}