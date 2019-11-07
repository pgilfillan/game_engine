#pragma once

#include <string>
#include <memory>

#include "Object.hpp"

class Scene {

public:
    Scene(std::string& name): name_(name) {}
    void load();
    void render();

private:
    std::string name_;
    std::shared_ptr<Object> root_;
};
