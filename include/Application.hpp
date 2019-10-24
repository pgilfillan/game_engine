#pragma once

#include "Scene.hpp"

struct GLFWwindow;

// No game logic
class Application {
public:
    Application();
    int glfwSetUp();
    int glewSetUp();
    ~Application();

    bool start();
    bool pause();
    void setScene(Scene s);

private:
    GLFWwindow* window;
    Scene s;
};
