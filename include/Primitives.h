#pragma once

#include <Mesh.h>

namespace ICCore {
    inline Mesh Cube() {
        // Vertices
        static const std::vector<Vertex> vertices = {
            // Front face (+Z)
            {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {0, 0}},
            {{0.5f, -0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {1, 0}},
            {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {1, 1}},

            {{0.5f, 0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {1, 1}},
            {{-0.5f, 0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {0, 1}},
            {{-0.5f, -0.5f, 0.5f}, {0, 0, 1}, {1, 0, 0}, {0, 0}},

            // Back face (-Z)
            {{0.5f, -0.5f, -0.5f}, {0, 0, -1}, {0, 1, 0}, {0, 0}},
            {{-0.5f, -0.5f, -0.5f}, {0, 0, -1}, {0, 1, 0}, {1, 0}},
            {{-0.5f, 0.5f, -0.5f}, {0, 0, -1}, {0, 1, 0}, {1, 1}},

            {{-0.5f, 0.5f, -0.5f}, {0, 0, -1}, {0, 1, 0}, {1, 1}},
            {{0.5f, 0.5f, -0.5f}, {0, 0, -1}, {0, 1, 0}, {0, 1}},
            {{0.5f, -0.5f, -0.5f}, {0, 0, -1}, {0, 1, 0}, {0, 0}},

            // Left face (-X)
            {{-0.5f, -0.5f, -0.5f}, {-1, 0, 0}, {0, 0, 1}, {0, 0}},
            {{-0.5f, -0.5f, 0.5f}, {-1, 0, 0}, {0, 0, 1}, {1, 0}},
            {{-0.5f, 0.5f, 0.5f}, {-1, 0, 0}, {0, 0, 1}, {1, 1}},

            {{-0.5f, 0.5f, 0.5f}, {-1, 0, 0}, {0, 0, 1}, {1, 1}},
            {{-0.5f, 0.5f, -0.5f}, {-1, 0, 0}, {0, 0, 1}, {0, 1}},
            {{-0.5f, -0.5f, -0.5f}, {-1, 0, 0}, {0, 0, 1}, {0, 0}},

            // Right face (+X)
            {{0.5f, -0.5f, 0.5f}, {1, 0, 0}, {1, 1, 0}, {0, 0}},
            {{0.5f, -0.5f, -0.5f}, {1, 0, 0}, {1, 1, 0}, {1, 0}},
            {{0.5f, 0.5f, -0.5f}, {1, 0, 0}, {1, 1, 0}, {1, 1}},

            {{0.5f, 0.5f, -0.5f}, {1, 0, 0}, {1, 1, 0}, {1, 1}},
            {{0.5f, 0.5f, 0.5f}, {1, 0, 0}, {1, 1, 0}, {0, 1}},
            {{0.5f, -0.5f, 0.5f}, {1, 0, 0}, {1, 1, 0}, {0, 0}},

            // Top face (+Y)
            {{-0.5f, 0.5f, 0.5f}, {0, 1, 0}, {1, 0, 1}, {0, 0}},
            {{0.5f, 0.5f, 0.5f}, {0, 1, 0}, {1, 0, 1}, {1, 0}},
            {{0.5f, 0.5f, -0.5f}, {0, 1, 0}, {1, 0, 1}, {1, 1}},

            {{0.5f, 0.5f, -0.5f}, {0, 1, 0}, {1, 0, 1}, {1, 1}},
            {{-0.5f, 0.5f, -0.5f}, {0, 1, 0}, {1, 0, 1}, {0, 1}},
            {{-0.5f, 0.5f, 0.5f}, {0, 1, 0}, {1, 0, 1}, {0, 0}},

            // Bottom face (-Y)
            {{-0.5f, -0.5f, -0.5f}, {0, -1, 0}, {0, 1, 1}, {0, 0}},
            {{0.5f, -0.5f, -0.5f}, {0, -1, 0}, {0, 1, 1}, {1, 0}},
            {{0.5f, -0.5f, 0.5f}, {0, -1, 0}, {0, 1, 1}, {1, 1}},

            {{0.5f, -0.5f, 0.5f}, {0, -1, 0}, {0, 1, 1}, {1, 1}},
            {{-0.5f, -0.5f, 0.5f}, {0, -1, 0}, {0, 1, 1}, {0, 1}},
            {{-0.5f, -0.5f, -0.5f}, {0, -1, 0}, {0, 1, 1}, {0, 0}},
        };

        static const std::vector<uint32_t> indices = {
            0, 1, 2, 3, 4, 5, // Front face
            6, 7, 8, 9, 10, 11, // Back face
            12, 13, 14, 15, 16, 17, // Left face
            18, 19, 20, 21, 22, 23, // Right face
            24, 25, 26, 27, 28, 29, // Top face
            30, 31, 32, 33, 34, 35, // Bottom face
        };

        Mesh mesh;
        mesh.SetVertices(vertices);
        mesh.SetIndices(indices);

        return mesh;
    }

    inline Mesh Plane(float scale = 1, uint8_t subdivisions = 0) {
        Mesh mesh;
        int vertCount = subdivisions * subdivisions + 2;

        std::vector<Vertex> vertices;
        std::vector<uint32_t> indices;
        float spacing = scale / (vertCount - 1);
        for (int y = 0; y < vertCount; y++) {
            float yPos = spacing * y;
            for (int x = 0; x < vertCount; x++) {
                float xPos = spacing * x;
                int vertNum = y * vertCount + x;

                vertices.push_back({{xPos, 0.0f, yPos}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f},
                                    {static_cast<float>(x) / (vertCount - 1),
                                     static_cast<float>(y) / (vertCount - 1)}});

                if (x != vertCount - 1 && y != vertCount - 1) {
                    indices.push_back(vertNum);
                    indices.push_back(vertNum + 1);
                    indices.push_back(vertNum + vertCount);

                    indices.push_back(vertNum + 1);
                    indices.push_back(vertNum + 1 + vertCount);
                    indices.push_back(vertNum + vertCount);
                }
            }
        }

        mesh.SetVertices(vertices);
        mesh.SetIndices(indices);
        return mesh;
    }
}