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
    void initCooldown();

    float attackCoolDownMAX2;

    void updateAttack();

public:
    BugAlien();
    BugAlien(sf::Vector2f pos);
    void attack(std::vector<Bullet*> &_enemy_bullets);
    virtual ~BugAlien();
    void update();
    bool canAttack();

};


#endif //GAMEPROJECT_BUGALIEN_H
