#pragma once
#include "Data.h"

#include <memory>
#include <vector>

namespace ICCore {
    class Mesh {
    public:
        Mesh();

        const std::vector<uint32_t> &GetIndices() const { return *_indices; }
        const std::vector<Vertex> &GetVertices() const { return *_vertices; }

        void SetVertices(const std::vector<Vertex> &vertices);

        void SetIndices(const std::vector<uint32_t> &indices);

    private:
        std::unique_ptr<std::vector<Vertex> > _vertices;
        std::unique_ptr<std::vector<uint32_t> > _indices;
    };
}