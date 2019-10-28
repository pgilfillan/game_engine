#pragma once

#include <memory>
#include <GL/glew.h>

class Texture {
public:
    Texture(GLuint id): id_(id) {}
    static std::unique_ptr<Texture> fromFile(const char* imagePath);
    const GLuint id() const;
private:
    GLuint id_;
};