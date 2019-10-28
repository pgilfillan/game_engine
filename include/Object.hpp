#pragma once

#include <memory>
#include <utility>
#include <vector>
#include "RenderComponent.hpp"
#include "Transform.hpp"

class Object {

public:
    Object(std::unique_ptr<RenderComponent> renderComponent = std::unique_ptr<RenderComponent>());
    Object(std::unique_ptr<Transform> transform, 
            std::unique_ptr<RenderComponent> renderComponent = std::unique_ptr<RenderComponent>()): 
        renderComponent_(std::move(renderComponent)), transform_(std::move(transform)) {}

    void setParent(std::shared_ptr<Object> newParent) {parent_ = newParent;}
    void setTransform(std::unique_ptr<Transform> newTransform) {transform_ = std::move(newTransform);}
    void render();

private:
    std::unique_ptr<RenderComponent> renderComponent_;
    std::unique_ptr<Transform> transform_;
    std::weak_ptr<Object> parent_;
    std::vector<std::weak_ptr<Object>> children_;
};
