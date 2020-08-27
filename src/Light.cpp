#include "Light.hpp"
#include <glm/glm.hpp>

Light::~Light() {}

Light::Light(const glm::vec4& pos, const glm::vec3 intensity, const glm::vec3 ambient):
    pos_(pos), intensity_(intensity), ambient_(ambient) {}

DirectionalLight::DirectionalLight(const glm::vec3& direction, const glm::vec3 intensity, const glm::vec3 ambient):
    Light(glm::vec4(direction, 0), intensity, ambient) {}

PositionalLight::PositionalLight(const glm::vec3& position, const glm::vec3 intensity, const glm::vec3 ambient):
    Light(glm::vec4(position, 1), intensity, ambient) {}