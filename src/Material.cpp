#include "Material.hpp"
#include "Shader.hpp"

void Material::use() {
    shader_->use();
    setValue("textureSampler", 0, Shader::UniformType::Integer1);
}