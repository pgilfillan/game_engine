#include "Scene.hpp"
#include "Camera.hpp"

void Scene::setCamera(const std::shared_ptr<Camera>& newCamera) {
    camera_ = newCamera;
}

void Scene::load() {
    root_->initRecursive();    
}

void Scene::render() {
    if (!camera_) return;
    root_->render(camera_->getProjection() * camera_->getView());
}

void Scene::update() {
    root_->updateRecursive();
}