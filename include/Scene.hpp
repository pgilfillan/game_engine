#pragma once

#include <string>
#include <memory>
#include "Object.hpp"

class Camera;

class Scene {

public:
    Scene(const std::string& name);
    void setCamera(const std::shared_ptr<Camera>& newCamera);
    void load();
    void render();
    void update();
    const std::string& name() {return name_;}
    const std::shared_ptr<Object> getRoot() {return root_;}

private:
    std::string name_;
    std::shared_ptr<Object> root_;
    std::shared_ptr<Camera> camera_;
};
