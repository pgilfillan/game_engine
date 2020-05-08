#pragma once

#include <map>
#include <string>
#include "Texture.hpp"
#include "Shader.hpp"

class Material {
public:
    Material(std::shared_ptr<Shader> shader, std::unique_ptr<Texture> diffuseTexture): 
            shader_(shader), diffuseTexture_(std::move(diffuseTexture)) {}
    Material() = default;

    void setShader(std::shared_ptr<Shader> newShader) {shader_ = newShader;}
    void setDiffuseTexture(std::unique_ptr<Texture> newDiffuseTexture) {diffuseTexture_ = std::move(newDiffuseTexture);}
    std::shared_ptr<Shader> getShader() {return shader_;}
    void use();

    template <typename ValueType> 
    void setValue(const std::string& key, const ValueType& newValue, const Shader::UniformType& type) {
        if (shader_) {
            shader_->setValue<ValueType>(key, newValue, type);
        }
    }

    template <typename ValueType> 
    void setMatrixValue(const std::string& key, const ValueType& newValue, const Shader::UniformType& type) {
        if (shader_) {
            shader_->setMatrixValue<ValueType>(key, newValue, type);
        }
    }

private:
    std::shared_ptr<Shader> shader_;
    std::unique_ptr<Texture> diffuseTexture_;
};