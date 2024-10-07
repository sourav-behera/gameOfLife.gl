#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <sstream>
#include <iostream>

#include <glad/glad.h>

enum ShaderType {
    VERTEX_SHADER,
    FRAGMENT_SHADER
};

class Shader {
    private:
        GLuint shaderID;
    public:
        Shader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);        
        void CheckShaderCompileStatus(const GLuint* shader, ShaderType shaderType) const;
        void CheckProgramLinkStatus(const GLuint* shaderProgram) const;
        void Use() const;
};

#endif