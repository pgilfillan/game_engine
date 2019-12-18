#pragma once

#include <GL/glew.h>
#include <memory>

class Shader {

public:
    Shader(GLuint programId): programId_(programId) {}
    ~Shader();
    static std::shared_ptr<Shader> fromFiles(const char* vsName, const char* fsName);
    void use();

//private: TODO: hide programId_
    GLuint programId_;
};