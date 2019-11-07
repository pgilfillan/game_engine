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
        if (auto c = child.lock()) {
            c->render();
        }
    }
}

void Object::init() {

}

void Object::initRecursive() {
    init();
    for (auto& child : children_) {
        child.initRecursive();
    }
}