#pragma once

#include <glm/glm.hpp>
#include <vector>

class Mesh {

public:
    static std::unique_ptr<Mesh> from_OBJ(const char * path);

private:
    std::vector<glm::vec3> vertices_;
    std::vector<glm::vec2> uvs_;
    std::vector<glm::vec3> normals_;
};
