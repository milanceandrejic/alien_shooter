//
// Created by Milance Andrejic on 21.6.22..
//

#include "FireAlien.h"
#include "Game.h"

void FireAlien::initSprite()
{
    //Set texture to the sprite
    this->sprite.setTexture(this->texture);
    //Resize
    this->sprite.scale(1.f,1.f);

    this->sprite.setPosition(250.0f ,0.0f);
}

void FireAlien::initTexture()
{
    if(!this->texture.loadFromFile("/Users/milanceandrejic/CLionProjects/GameProject/textures/spr_enemy_01.png"))
    {
        std::cerr<< "ERROR::FIREALIEN::INIT_TEXTURE: Can not load texture\n";
    }
    FireAlien::initBulletTexture();
}

FireAlien::FireAlien() : Monster(4,20,0.2f,10)
{
    initTexture();
    initSprite();
    this->initHPBar();
    this->initCooldown();
}

FireAlien::~FireAlien()
{

}

FireAlien::FireAlien(sf::Vector2f pos) : Monster(6,20,0.2f,10)
{
    initTexture();
    initSprite();
    this->sprite.setPosition(pos);
    this->initHPBar();
    this->initCooldown();
}

bool FireAlien::canAttack()
{
    if(this->attackCoolDown >= this->attackCoolDownMAX)
    {
        this->attackCoolDown = 0.f;
        return true;
    }
    return false;
}

void FireAlien::initCooldown()
{
    this->attackCoolDownMAX = 400.f;
    this->attackCoolDown=attackCoolDownMAX;
}

void FireAlien::attack(std::vector<Bullet *> &_enemy_bullets)
{
    if(this->canAttack())
        _enemy_bullets.push_back(new Bullet(&bulletTexture,
                                            this->getPosition().x + 10.f,
                                            this->getPosition().y + 5.f,
                                            this->direction.x,
                                            this->direction.y,
                                            0.8f));
}

void FireAlien::updateAttack()
{
    if(this->attackCoolDown < this->attackCoolDownMAX)
    {
        this->attackCoolDown += 1.f;
    }
}

void FireAlien::update()
{
    Monster::update();
    updateAttack();
}

void FireAlien::initBulletTexture()
{
    if(!bulletTexture.loadFromFile("/Users/milanceandrejic/CLionProjects/GameProject/textures/enemy_bulet.png"))
    {
        std::cerr<< "ERROR::FIREALIEN::INIT_TEXTURE: Can not load bullet texture\n";
    }
}

