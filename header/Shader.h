#ifndef SHADER_H
#define SHADER_H
#include <GL/glew.h>
#include <iostream>
class Shader{
    private:
    unsigned int ID;

    public:
    bool CreateShader(std::string VertexSourcePath,std::string FragmentSourcePath);
    void Use();
    unsigned int getID();
};

#endif