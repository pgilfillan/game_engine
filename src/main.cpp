#include "Shader.hpp"
#include "Texture.hpp"
#include "util.hpp"
#include "Camera.hpp"
#include "Application.hpp"
#include "Object.hpp"
#include "Transform.hpp"
#include "Mesh.hpp"
#include "Material.hpp"
#include "Light.hpp"
#include <iostream>

int main() {
    Application app;

    // Cube transform
    std::unique_ptr<Transform> cubeTransform(new Transform(0, 0, 0, 0, 0, 0, 1, 1, 1));

    // Cube render information
    auto cubeMesh = Mesh::from_OBJ("../res/models/cube.obj");
    auto cubeTexture = Texture::fromFile("../res/textures/uvtemplate.bmp");
    auto cubeShader = Shader::fromFiles("../res/shaders/phong_vs.glsl", "../res/shaders/phong_fs.glsl");
    std::unique_ptr<Material> cubeMaterial(new Material(cubeShader, std::move(cubeTexture)));

    // Create cube object
    std::shared_ptr<Object> cubeObject(new Object(std::move(cubeTransform), std::move(cubeMesh), std::move(cubeMaterial)));

    // Create scene containing cube, camera and light
    std::shared_ptr<Scene> mainScene(new Scene(std::string("Main scene")));
    mainScene->getRoot()->addChild(cubeObject);
    std::shared_ptr<Camera> cam(new Camera());
    mainScene->setCamera(cam);
	std::shared_ptr<Light> light(new DirectionalLight(glm::vec3(4, 1, 2), glm::vec3(1, 1, 1), glm::vec3(0.5f, 0.5f, 0.5f)));
	mainScene->setLight(light);

    // Set application to use this scene, then start
    app.addScene(mainScene);
    app.setCurrentScene("Main scene");
    std::cout << "Starting application\n";
    app.start();

    return 0;
}