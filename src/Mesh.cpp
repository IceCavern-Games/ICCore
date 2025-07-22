#include <Mesh.h>

namespace ICCore {
    Mesh::Mesh(Material &material) {
        SetMaterial(material);
    }

    void Mesh::Bind() {
        _material->GetShader().Bind();
    }

    void Mesh::SetIndices(const std::vector<uint32_t> &indices) {
        _indices = std::make_unique<std::vector<uint32_t>>(indices);
    }

    void Mesh::SetVertices(const std::vector<Vertex> &vertices) {
        _vertices = std::make_unique<std::vector<Vertex>>(vertices);
    }

} // namespace ICCore