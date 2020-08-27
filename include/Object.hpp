#pragma once

#include <GL/glew.h>
#include <memory>
#include <utility>
#include <vector>
#include "Transform.hpp"
#include "Mesh.hpp"
#include "Material.hpp"

class Light;

class Object {

public:
    Object(std::unique_ptr<Transform> transform = std::unique_ptr<Transform>(), 
            std::unique_ptr<Mesh> mesh = std::unique_ptr<Mesh>(), 
            std::unique_ptr<Material> material = std::unique_ptr<Material>()): 
        mesh_(std::move(mesh)), material_(std::move(material)), transform_(std::move(transform)) {}
    virtual ~Object();

    void init();
    void initRecursive();
    void setParent(std::shared_ptr<Object> newParent) {parent_ = newParent;}
    void setTransform(std::unique_ptr<Transform> newTransform) {transform_ = std::move(newTransform);}
    void setMesh(std::unique_ptr<Mesh> newMesh) {mesh_ = std::move(newMesh);}
    void setMaterial(std::unique_ptr<Material> newMaterial) {material_ = std::move(newMaterial);}
    void render(const glm::mat4& view, const glm::mat4& projectionViewMatrix, const Light& light);
    virtual void update();
    void updateRecursive();
    const std::vector<std::weak_ptr<Object>> getChildren();
    void addChild(std::shared_ptr<Object> newChild);

private:
    // Rendering
    std::unique_ptr<Mesh> mesh_;
    std::unique_ptr<Material> material_;
    GLuint vao_;
    GLuint vertexBuffer_;
    GLuint uvBuffer_;
    GLuint normalsBuffer_;

    // Transform
    std::unique_ptr<Transform> transform_;

    // Scene hierarchy
    std::weak_ptr<Object> parent_;
    std::vector<std::shared_ptr<Object>> children_;
};
