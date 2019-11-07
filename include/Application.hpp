#pragma once

#include <memory>
#include <vector>
#include "Scene.hpp"

struct GLFWwindow;

class Application {
public:
    Application();
    ~Application();

    void start();
    void addScene(Scene s);
    void setCurrentScene(std::string& sceneName);

    GLFWwindow* const getWindow() const {return window;}

private:
    int glfwSetUp();
    int glewSetUp();

    std::vector<std::shared_ptr<Scene>> scenes_;
    std::shared_ptr<Scene> currScene_;
    GLFWwindow* window_;
    std::unique_ptr<Scene> scene_;
};
