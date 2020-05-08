#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.hpp"
#include "Texture.hpp"
#include "util.hpp"
#include "ModelLoading.hpp"
#include "Camera.hpp"
#include "Application.hpp"
#include "Object.hpp"
#include "Transform.hpp"
#include "Mesh.hpp"
#include "Material.hpp"

int main() {
    Application a;
    auto window = a.getWindow();

    //Set up vertex array
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //Enable input
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    //Set up shaders
    auto shader = Shader::fromFiles("../res/shaders/simpleVShader.vs", "../res/shaders/simpleFShader.fs");
    auto program = shader->programId_; // TODO: hide programId_

    //Initialise camera
    Camera cam;

    //Initialise MVP matrix
    GLuint matrixID = glGetUniformLocation(program, "MVP");
    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    glm::mat4 View       = cam.getView();
    glm::mat4 Model      = glm::mat4(1.0f);
    glm::mat4 MVP        = Projection * View * Model;

    //Load textures
    GLuint textureID = glGetUniformLocation(program, "myTextureSampler");
    auto firstTex = Texture::fromFile("../res/textures/uvtemplate.bmp");

    //Load models
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals; // Won't be used at the moment.
    bool res = loadOBJ("../res/models/cube.obj", vertices, uvs, normals);
    if (!res) {
        return 1;
    }

    //Set up buffers
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    //Draw window, exit on ShouldClose or escape key
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(program);

        glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, firstTex->id());
        glUniform1i(textureID, 0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            2,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
        );

        glDrawArrays(GL_TRIANGLES, 0, 12*3);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    //Cleanup
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteProgram(program);
    glDeleteVertexArrays(1, &vao);

    return 0;
}

int othermain() {
    // Cube transform
    std::unique_ptr<Transform> cubeTransform(new Transform(0, 0, 0, 0, 0, 0, 1, 1, 1));

    // Cube render information
    auto cubeMesh = Mesh::from_OBJ("../res/models/cube.obj");
    auto cubeTexture = Texture::fromFile("../res/textures/uvtemplate.bmp");
    auto cubeShader = Shader::fromFiles("../res/shaders/simpleVShader.vs", "../res/shaders/simpleFShader.fs");
    std::unique_ptr<Material> cubeMaterial(new Material(cubeShader, std::move(cubeTexture)));
    
    // Create cube object
    std::shared_ptr<Object> cubeObject(new Object(std::move(cubeTransform), std::move(cubeMesh), std::move(cubeMaterial)));

    // Create scene containing cube
    std::shared_ptr<Scene> mainScene(new Scene(std::string("Main scene")));
    mainScene->getRoot()->addChild(cubeObject);

    // Set application to use this scene, then start
    Application app;
    app.addScene(mainScene);
    app.setCurrentScene("Main scene");
    app.start();

    return 0;
}