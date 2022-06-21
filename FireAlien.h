//
// Created by Milance Andrejic on 21.6.22..
//

#ifndef GAMEPROJECT_FIREALIEN_H
#define GAMEPROJECT_FIREALIEN_H
#include "Monster.h"
static sf::Texture bulletTexture;
class FireAlien : public Monster {
private:
    void initTexture();
    void initSprite();
    void initCooldown();

    void updateAttack();

    static void initBulletTexture();

public:
    FireAlien();
    FireAlien(sf::Vector2f pos);
    bool canAttack();
    virtual ~FireAlien();
    void attack(std::vector<Bullet*> &_enemy_bullets);
    void update();

};


#endif //GAMEPROJECT_FIREALIEN_H
