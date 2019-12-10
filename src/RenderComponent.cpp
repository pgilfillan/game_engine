#include "RenderComponent.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Material.hpp"

#include <glm/glm.hpp>

// Everything loaded from files already
RenderComponent::RenderComponent(std::unique_ptr<Mesh> mesh, std::unique_ptr<Texture> tex, 
                std::unique_ptr<Shader> shader, std::unique_ptr<Material> mat) {

    mesh_ = std::move(mesh);
    texture_ = std::move(tex);
    shader_ = std::move(shader);
    material_ = std::move(mat);
}

RenderComponent::~RenderComponent() {
    shutdown();
}

void RenderComponent::init() {
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

void RenderComponent::shutdown() {
    glDeleteBuffers(1, &vertexBuffer_);
    glDeleteBuffers(1, &uvBuffer_);
    //glDeleteBuffers(1, &normalsBuffer_);
    glDeleteVertexArrays(1, &vao_);
}

void RenderComponent::render() {
    shader_->use();
    glBindVertexArray(vao_);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        2,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );
    glDrawArrays(GL_TRIANGLES, 0, 12*3);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
