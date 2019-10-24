#pragma once

#include "Scene.hpp"

struct GLFWwindow;

class Application {
public:
    Application();
    ~Application();

    bool start();
    bool pause();
    void setScene(Scene s);

    GLFWwindow* const getWindow() const {return window;}

private:
    int glfwSetUp();
    int glewSetUp();
    GLFWwindow* window;
    Scene s;
};
