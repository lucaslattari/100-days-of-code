#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader
{
public:
    GLuint program;

    Shader (const GLchar* vertexPath, const GLchar* fragmentPath)
    {
        std::string     vertexCode;
        std::string     fragmentCode;
        std::ifstream   vertexShaderFile;
        std::ifstream   fragmentShaderFile;

        vertexShaderFile.exceptions(std::ifstream::badbit);
        fragmentShaderFile.exceptions(std::ifstream::badbit);
        try
        {
            vertexShaderFile.open(vertexPath);
            fragmentShaderFile.open(fragmentPath);
            std::stringstream vertexShaderStream, fragmentShaderStream;

            vertexShaderStream << vertexShaderFile.rdbuf();
            fragmentShaderStream << fragmentShaderFile.rdbuf();

            vertexShaderFile.close();
            fragmentShaderFile.close();

            vertexCode      = vertexShaderStream.str();
            fragmentCode    = fragmentShaderStream.str();
        }
        catch(std::ifstream::failure e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }

        const std::string vertexShaderCode      = vertexCode.c_str();
        const std::string fragmentShaderCode    = fragmentCode.c_str();

        GLuint vertexID, fragmentID;
        GLint success;
        GLchar infoLog[512];

        vertexID = glCreateShader(GL_VERTEX_SHADER);
        const char* vertexShaderCodeInC = vertexShaderCode.c_str();
        glShaderSource(vertexID, 1, &vertexShaderCodeInC, nullptr);
        glCompileShader(vertexID);

        glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(vertexID, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fragmentShaderCodeInC = fragmentShaderCode.c_str();
        glShaderSource(fragmentID, 1, &fragmentShaderCodeInC, nullptr);
        glCompileShader(fragmentID);

        glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(fragmentID, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        this->program = glCreateProgram();
        glAttachShader(this->program, vertexID);
        glAttachShader(this->program, fragmentID);
        glLinkProgram(this->program);

        glGetProgramiv(this->program, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
    }

    void Use()
    {
        glUseProgram(this->program);
    }
};

#endif // SHADER_H_
