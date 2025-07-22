#pragma once
#include "Data.h"
#include "Material.h"

#include <memory>
#include <vector>

namespace ICCore {
    class Mesh {
    public:
        Mesh() = default;
        Mesh(Material &material);

        void Bind();
        const std::vector<uint32_t> &GetIndices() const { return *_indices; }
        const std::vector<Vertex> &GetVertices() const { return *_vertices; }
        const Material &GetMaterial() const { return *_material; }

        void SetVertices(const std::vector<Vertex> &vertices);
        void SetIndices(const std::vector<uint32_t> &indices);
        void SetMaterial(const Material &material) { _material = std::make_shared<Material>(material); }

    private:
        std::shared_ptr<Material> _material;

        std::unique_ptr<std::vector<Vertex>> _vertices;
        std::unique_ptr<std::vector<uint32_t>> _indices;
    };
} // namespace ICCore