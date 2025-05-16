#ifndef GAME_H
#define GAME_H
#include <Shader.h>
#include <Texture.h>
#include <map>
#include <string>
class Game{
    private:
    std::map<std::string,Shader> Shaders;
    std::map<std::string,Texture> Textures;
    
    public:
    void Init();
    void Render();
    void Update();
};
#endif