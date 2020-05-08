#pragma once

#include <GL/glew.h>
#include <memory>
#include <string>

class Shader {

public:
    enum UniformType {
        Matrix4x4,
    };

    Shader(GLuint programId): programId_(programId) {}
    ~Shader();
    static std::shared_ptr<Shader> fromFiles(const char* vsName, const char* fsName);
    void use();

    template <typename ValueType>
    void setValue(const std::string& key, const ValueType& newValue, const UniformType& type) {
        GLuint matrixID = glGetUniformLocation(programId_, key.c_str());
        switch (type) {
        case Matrix4x4:
            glUniformMatrix4fv(matrixID, 1, GL_FALSE, &newValue[0][0]);
            break;
        }
    }

//private: TODO: hide programId_
    GLuint programId_;
};