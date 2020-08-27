#pragma once

#include <glm/glm.hpp>

class Light {

public:
    virtual ~Light() = 0;

    const glm::vec4& getPos() const;
    const glm::vec3& getIntensity() const;
    const glm::vec3& getAmbient() const;

protected:
    Light(const glm::vec4& pos, const glm::vec3 intensity, const glm::vec3 ambient);
    glm::vec4 pos_;
    glm::vec3 intensity_;

    // TODO: move ambient intesity out of individual lights
    glm::vec3 ambient_;
};


class DirectionalLight : public Light {
public:
    DirectionalLight(const glm::vec3& direction, const glm::vec3 intensity, const glm::vec3 ambient);
    ~DirectionalLight() = default;
};

class PositionalLight : public Light {
public:
    PositionalLight(const glm::vec3& position, const glm::vec3 intensity, const glm::vec3 ambient);
    ~PositionalLight() = default;
};