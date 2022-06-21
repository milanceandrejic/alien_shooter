//
// Created by Milance Andrejic on 20.6.22..
//

#include "BugAlien.h"


void BugAlien::initSprite()
{
    //Set texture to the sprite
    this->sprite.setTexture(this->texture);
    //Resize
    this->sprite.scale(1.f,1.f);

    this->sprite.setPosition(250.0f ,0.0f);
}

void BugAlien::initTexture()
{
    if(!this->texture.loadFromFile("/Users/milanceandrejic/CLionProjects/GameProject/textures/spr_drone_00.png"))
    {
        std::cout<< "ERROR::BUGALIEN::INIT_TEXTURE: Can not load texture\n";
    }
}

BugAlien::BugAlien() : Monster(4,10,0.2f,10)
{
    initTexture();
    initSprite();
    this->initHPBar();
    this->initCooldown();
}

BugAlien::~BugAlien()
{

}

BugAlien::BugAlien(sf::Vector2f pos) : Monster(4,10,0.5f,10)
{
    initTexture();
    initSprite();
    this->sprite.setPosition(pos);
    this->initHPBar();
    this->initCooldown();
}

void BugAlien::attack(std::vector<Bullet *> &_enemy_bullets)
{
    if(canAttack())
        this->speed = 2.3f;
    else
        this->speed = 0.5f;
}

void BugAlien::updateAttack()
{
    if(this->attackCoolDown < this->attackCoolDownMAX2)
    {
        this->attackCoolDown += 1.f;
    }
}

void BugAlien::initCooldown()
{
    this->attackCoolDownMAX2 = 560.f;
    this->attackCoolDownMAX = 500.f;
    this->attackCoolDown = attackCoolDownMAX2;
}

void BugAlien::update()
{
    Monster::update();
    this->updateAttack();
}

bool BugAlien::canAttack()
{
    if(this->attackCoolDown >= this->attackCoolDownMAX2)
    {
        this->attackCoolDown = 0.f;
    }
    if(this->attackCoolDown >= this->attackCoolDownMAX)
    {
        return true;
    }

    return false;
}
