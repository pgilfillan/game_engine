#pragma once

#include <glm/glm.hpp>
#include <memory>

struct Transform
{
    Transform(glm::vec3& position, glm::vec3& rotation, glm::vec3& scale): 
        position(position), rotation(rotation), scale(scale) {}

    Transform(int pos1, int pos2, int pos3, int rot1, int rot2, int rot3, int scale1, int scale2, int scale3):
        position(glm::vec3(pos1, pos2, pos3)), rotation(glm::vec3(rot1, rot2, rot3)),
        scale(glm::vec3(scale1, scale2, scale3)) {}

    Transform(float pos1, float pos2, float pos3, float rot1, float rot2, float rot3, float scale1, 
            float scale2, float scale3):
        position(glm::vec3(pos1, pos2, pos3)), rotation(glm::vec3(rot1, rot2, rot3)),
        scale(glm::vec3(scale1, scale2, scale3)) {}

    glm::vec3 position;
    glm::vec3 rotation; // TODO: proper rotation
    glm::vec3 scale;
};
