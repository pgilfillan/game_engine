#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

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
    Application app;

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
    std::shared_ptr<Camera> cam(new Camera());
    mainScene->setCamera(cam);

    // Set application to use this scene, then start
    app.addScene(mainScene);
    app.setCurrentScene("Main scene");
    app.start();

    return 0;
}