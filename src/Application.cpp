#include "Application.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int Application::glfwSetUp() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialise GLFW\n");
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow( 1024, 768, "First", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to create window\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    return 0;
}

int Application::glewSetUp() {
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    } else {
        return 0;
    }
}

Application::Application() {
    glfwSetUp();
    //if (glfwInit) return glfwInit;

    glewSetUp();
    //if (glewInit) return glewInit;
}

Application::~Application() {
    glfwTerminate();
}