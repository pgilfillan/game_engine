#include "Material.hpp"
#include "Shader.hpp"

void Material::use() {
    shader_->use();
}