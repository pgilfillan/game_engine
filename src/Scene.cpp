#include "Scene.hpp"
#include "Camera.hpp"
#include "Light.hpp"

Scene::Scene(const std::string& name): name_(name), root_(new Object()) {}

void Scene::setCamera(const std::shared_ptr<Camera>& newCamera) {
    camera_ = newCamera;
}

void Scene::setLight(const std::shared_ptr<Light>& newLight) {
	light_ = newLight;
}

void Scene::load() {
    root_->initRecursive();    
}

void Scene::render() {
    if (!camera_ || !light_) return;
    root_->render(camera_->getView(), camera_->getProjection() * camera_->getView(), *light_);
}

void Scene::update() {
    root_->updateRecursive();
}