#include "Shader.hpp"
#include "util.hpp"

char* fileToBuffer(const char* file);

std::shared_ptr<Shader> Shader::fromFiles(const char *vsName, const char *fsName) {
    GLuint programId = glCreateProgram();

    //Open vertex shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    GLchar *vs_source = fileToBuffer(vsName);
    if (!vs_source) {
        Util::panic("Failed to open vertex shader\n");
    }
    glShaderSource(vs, 1, &vs_source, NULL);
    glCompileShader(vs);

    //Open fragment shader
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    GLchar *fs_source = fileToBuffer(fsName);
    if (!fs_source) {
        Util::panic("Failed to open fragment shader\n");
    }
    glShaderSource(fs, 1, &fs_source, NULL);
    glCompileShader(fs);

    glAttachShader(programId, vs);
    glAttachShader(programId, fs);

    glLinkProgram(programId);

    glDetachShader(programId, vs);
    glDetachShader(programId, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);

    return std::shared_ptr<Shader>(new Shader(programId));
}

Shader::~Shader() {
    glDeleteProgram(programId_);
}

void Shader::use() {
    glUseProgram(programId_);
}

char* fileToBuffer(const char* file) {
    FILE *fptr;
    long length;
    char *buf;

    fptr = fopen(file, "rb"); /* Open file for reading */
    if (!fptr) /* Return NULL on failure */
        return NULL;
    fseek(fptr, 0, SEEK_END); /* Seek to the end of the file */
    length = ftell(fptr); /* Find out how many bytes into the file we are */
    buf = (char*)malloc(length+1); /* Allocate a buffer for the entire length of the file and a null terminator */
    fseek(fptr, 0, SEEK_SET); /* Go back to the beginning of the file */
    fread(buf, length, 1, fptr); /* Read the contents of the file in to the buffer */
    fclose(fptr); /* Close the file */
    buf[length] = 0; /* Null terminator */

    return buf; /* Return the buffer */
}
