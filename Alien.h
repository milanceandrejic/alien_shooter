//
// Created by Milance Andrejic on 20.6.22..
//

#ifndef GAMEPROJECT_ALIEN_H
#define GAMEPROJECT_ALIEN_H
#include "Monster.h"

class Alien : public Monster{
private:

    void initTexture();
    void initSprite();
public:
    Alien();
    Alien(sf::Vector2f pos);
    virtual ~Alien();

};


#endif //GAMEPROJECT_ALIEN_H
