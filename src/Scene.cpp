#include "Scene.hpp"

void Scene::load() {
    root_->initRecursive();    
}

void Scene::render() {
    root_->render();
}

void Scene::update() {
    root_->updateRecursive();
}