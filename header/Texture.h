#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
class Texture{
    private:
    unsigned int ID;
    public:
    void CreateTexture(std::string TextureFile);
    void Use();
};
#endif