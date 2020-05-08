#pragma once

#include <memory>
#include <map>
#include "Scene.hpp"

struct GLFWwindow;

class Application {
public:
    Application();
    virtual ~Application();

    void start();
    void addScene(std::shared_ptr<Scene> s);
    void setCurrentScene(const std::string& sceneName);

    GLFWwindow* const getWindow() const {return window_;}

private:
    int glfwSetUp();
    int glewSetUp();

    std::map<std::string, std::shared_ptr<Scene>> scenes_;
    std::shared_ptr<Scene> currScene_;
    GLFWwindow* window_;
    std::unique_ptr<Scene> scene_;
};
