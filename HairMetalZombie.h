#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include"Zombi.h"


#ifndef HAIR_METAL_ZOMBIE_H
#define HAIR_METAL_ZOMBIE_H


class HairMetalZombie : public Zombi{
protected:
    void initTexture(std::string textureFilePath);
public:
    HairMetalZombie() : Zombi("extrafile/hairmetal.png", 0.4){};
};

#endif