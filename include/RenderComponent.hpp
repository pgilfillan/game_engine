#pragma once

#include <GL/glew.h>
#include <memory>
#include <utility>

struct Mesh;
class Texture;
class Shader;
class Material;

class RenderComponent {

public:
    RenderComponent(std::unique_ptr<Mesh> mesh, std::unique_ptr<Texture> tex, 
                    std::unique_ptr<Shader> shader, std::unique_ptr<Material> mat);
    ~RenderComponent();

    void init();
    void shutdown();
    void render();

private:
    std::unique_ptr<Mesh> mesh_;
    std::unique_ptr<Texture> texture_;
    std::unique_ptr<Shader> shader_;
    std::unique_ptr<Material> material_;

    GLuint vertexBuffer_;
    GLuint uvBuffer_;
    //GLuint normalsBuffer_;
    GLuint vao_;
};