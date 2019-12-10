#include "Object.hpp"
#include <glm/glm.hpp>
#include "Transform.hpp"

Object::Object(std::unique_ptr<RenderComponent> renderComponent) {
    renderComponent_ = std::move(renderComponent);
    transform_ = std::unique_ptr<Transform>(new Transform(0, 0, 0, 0, 0, 0, 0, 0, 0));
}

void Object::render() {
    if (renderComponent_) {
        renderComponent_->render();
    }

    for (auto& child : children_) {
        child->render();
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
    if (renderComponent_) {
        renderComponent_->init();
    }
}

void Object::initRecursive() {
    init();
    for (auto& child : children_) {
        child->initRecursive();
    }
}