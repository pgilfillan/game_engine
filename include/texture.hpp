#pragma once

#include <GL/glew.h>
#include <memory>

class Texture {
public:
    Texture(GLuint id): id_(id) {}
    ~Texture();
    static std::unique_ptr<Texture> fromFile(const char* imagePath);
    const GLuint id() const;
private:
    GLuint id_;
};