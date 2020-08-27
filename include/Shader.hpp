#pragma once

#include <GL/glew.h>
#include <memory>
#include <string>

class Shader {

public:
    enum UniformType {
        Matrix4x4,
        Integer1,
        Float1,
        Float3,
        Float4
    };

    Shader(GLuint programId): programId_(programId) {}
    ~Shader();
    static std::shared_ptr<Shader> fromFiles(const char* vsName, const char* fsName);
    void use();

    template <typename ValueType>
    void setValue(const std::string& key, const ValueType& newValue, const UniformType& type) {
        GLuint uniformLocation = glGetUniformLocation(programId_, key.c_str());
        switch (type) {
        case Integer1:
            glUniform1i(uniformLocation, newValue);
            break;
        default:
            break;
        }
    }

    template <typename ValueType>
    void setVectorValue(const std::string& key, const ValueType& newValue, const UniformType& type) {
        GLuint uniformLocation = glGetUniformLocation(programId_, key.c_str());
        switch (type) {
        case Float3:
            glUniform3fv(uniformLocation, 1, &newValue[0]);
            break;
        case Float4:
            glUniform4fv(uniformLocation, 1, &newValue[0]);
            break;
        default:
            break;
        }
    }

    template <typename ValueType>
    void setMatrixValue(const std::string& key, const ValueType& newValue, const UniformType& type) {
        GLuint uniformLocation = glGetUniformLocation(programId_, key.c_str());
        switch (type) {
        case Matrix4x4:
            glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &newValue[0][0]);
            break;
        default:
            break;
        }
    }

private:
    GLuint programId_;
};