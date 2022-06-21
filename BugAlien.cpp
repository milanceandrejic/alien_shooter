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
    if(!this->texture.loadFromFile("/Users/milanceandrejic/CLionProjects/GameProject/textures/spr_drone_00.gif"))
    {
        std::cout<< "ERROR::BUGALIEN::INIT_TEXTURE: Can not load texture\n";
    }
}

BugAlien::BugAlien() : Monster(4,10,0.2f,10)
{
    initTexture();
    initSprite();
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
}