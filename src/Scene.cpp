#include "Scene.hpp"

void Scene::load() {
    root_.initRecursive();    
}

void Sceme::render() {
    root_.render();
}