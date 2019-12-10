#pragma once

#include <glm/glm.hpp>
#include <vector>

struct Mesh {
    static std::unique_ptr<Mesh> from_OBJ(const char * path);
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
};
