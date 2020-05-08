#include "Object.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Transform.hpp"
#include "Mesh.hpp"
#include "Material.hpp"
#include "Shader.hpp"

Object::~Object() {
    glDeleteBuffers(1, &vertexBuffer_);
    glDeleteBuffers(1, &uvBuffer_);
    //glDeleteBuffers(1, &normalsBuffer_);
    glDeleteVertexArrays(1, &vao_);
}

void Object::render(const glm::mat4& projectionViewMatrix) {
    // Render this object
    if (mesh_) {
        // TODO: rotation as well
        auto modelMatrix = glm::scale(glm::translate(glm::mat4(1.0f), transform_->position), transform_->scale);
        glm::mat4 MVP = projectionViewMatrix * modelMatrix;
        material_->setValue<glm::mat4>("MVP", MVP, Shader::UniformType::Matrix4x4);
        material_->use();
        glBindVertexArray(vao_);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size (3 floats to a vertex)
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);
        glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            2,                                // size (2 floats to a texture coordinate)
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
        );
        glDrawArrays(GL_TRIANGLES, 0, mesh_->vertices.size());

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
    }
    
    // Render each of the children
    for (auto& child : children_) {
        child->render(projectionViewMatrix);
    }
}

void Object::update() {

}

void Object::updateRecursive() {
    update();
    for (auto& child : children_) {
        child->updateRecursive();
    }
}

void Object::init() {
    if (mesh_) {
        // Initialise mesh
        glGenVertexArrays(1, &vao_);
        glBindVertexArray(vao_);

        glGenBuffers(1, &vertexBuffer_);
        glGenBuffers(1, &uvBuffer_);
        //glGenBuffers(1, &normalsbuffer_);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
        auto& vertices = mesh_->vertices;
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);
        auto& uvs = mesh_->uvs;
        glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
    }

}

void Object::initRecursive() {
    init();
    for (auto& child : children_) {
        child->initRecursive();
    }
}

void Object::addChild(std::shared_ptr<Object> newChild) {
    children_.push_back(newChild);
}