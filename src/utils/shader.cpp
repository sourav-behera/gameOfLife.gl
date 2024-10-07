#include <shader.h>

std::string load_from_file(const char* filePath) {
    std::stringstream ss;
    std::fstream fs;
    std::string s;

    fs.open(filePath);
    ss << fs.rdbuf();
    s = ss.str();
    fs.close();

    return s;
}

Shader::Shader(const char* vertexShaderFilePath, const char* fragmentShaderFilePath) {

    std::string s_vertexShaderCode = load_from_file(vertexShaderFilePath);
    std::string s_fragmentShaderCode = load_from_file(fragmentShaderFilePath);

    const char* vertexShaderCode = s_vertexShaderCode.c_str();
    const char* fragmentShaderCode = s_fragmentShaderCode.c_str();

    GLuint gluint_vertexShaderProgram = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(gluint_vertexShaderProgram, 1, &vertexShaderCode, nullptr);
    glCompileShader(gluint_vertexShaderProgram);
    CheckShaderCompileStatus(&gluint_vertexShaderProgram, VERTEX_SHADER);

    GLuint gluint_fragmentShaderProgram = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(gluint_fragmentShaderProgram, 1, &fragmentShaderCode, nullptr);
    glCompileShader(gluint_fragmentShaderProgram);
    CheckShaderCompileStatus(&gluint_fragmentShaderProgram, FRAGMENT_SHADER);

    shaderID = glCreateProgram();
    glAttachShader(shaderID, gluint_vertexShaderProgram);
    glAttachShader(shaderID, gluint_fragmentShaderProgram);
    glLinkProgram(shaderID);
    CheckProgramLinkStatus(&shaderID);

    glDeleteShader(gluint_vertexShaderProgram);
    glDeleteShader(gluint_fragmentShaderProgram);
}

void Shader::CheckShaderCompileStatus(const GLuint* shader, ShaderType shaderType) const {
    int success;
    char infoLog[512];
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(*shader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::" << (shaderType == VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::CheckProgramLinkStatus(const GLuint* shaderProgram) const {
    int success;
    char infoLog[512];
    glGetProgramiv(*shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(*shaderProgram, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::Use() const {
    glUseProgram(shaderID);
}