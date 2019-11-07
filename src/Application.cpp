#include "Application.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "util.hpp"

Application::Application() {
    auto successCode = glfwSetUp();
    if (successCode) Util::panic("GLFW failed to initialise");

    successCode = glewSetUp();
    if (successCode) Util::panic("GLEW failed to initialise");

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

Application::~Application() {
    glfwTerminate();
}

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

    window_ = glfwCreateWindow( 1024, 768, "First", NULL, NULL);
    if (!window_) {
        fprintf(stderr, "Failed to create window\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window_);
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

void Application::start() {
    if (scenes_.size() == 0) {
        panic("Cannot start the application with no given scenes");
        return;
    }

    if (!currScene_) {
        currScene_ = scenes_[0];
    }
    currScene_.load();

    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        currScene_.render();

        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}