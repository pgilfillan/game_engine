#pragma once

#include <string>
#include <memory>

#include "Object.hpp"

class Scene {
    Scene(std::string& name): name_(name) {}

private:
    std::string name_;
    std::unique_ptr<Object> root_;
};
