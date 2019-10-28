#include "RenderComponent.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Material.hpp"

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
    // Initialise buffers
}

void RenderComponent::shutdown() {
    // Delete buffers
    // Unload everything
}

void RenderComponent::render() {
    // Bind buffers and draw
}