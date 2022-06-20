//
// Created by Milance Andrejic on 20.6.22..
//

#ifndef GAMEPROJECT_BUGALIEN_H
#define GAMEPROJECT_BUGALIEN_H
#include "Monster.h"

class BugAlien : public Monster{
private:

    void initTexture();
    void initSprite();
public:
    BugAlien();
    BugAlien(sf::Vector2f pos);
    virtual ~BugAlien();


};


#endif //GAMEPROJECT_BUGALIEN_H
