#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include"Zombi.h"


#ifndef REGULAR_ZOMBIE_H
#define REGULAR_ZOMBIE_H


class RegularZombie : public Zombi{

public:
    RegularZombie() : Zombi("extrafile/Zombi.png", 0.18){};
};

#endif

