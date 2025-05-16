#ifndef GAME_H
#define GAME_H
#include <Shader.h>
#include <map>
#include <string>
class Game{
    private:
    std::map<std::string,Shader> Shaders;

    public:
    void Init();
    void Render();
    void Update();
};
#endif