//
// Created by Milance Andrejic on 20.6.22..
//

#include "Alien.h"

void Alien::initSprite()
{
    //Set texture to the sprite
    this->sprite.setTexture(this->texture);
    //Resize
    this->sprite.scale(1.f,1.f);

    this->sprite.setPosition(0.0f ,0.0f);
}

void Alien::initTexture()
{
    if(!this->texture.loadFromFile("/Users/milanceandrejic/CLionProjects/GameProject/textures/spr_enemy_03.gif"))
    {
        std::cout<< "ERROR::ALIEN::INIT_TEXTURE: Can not load texture\n";
    }
}

Alien::Alien() : Monster(2,5,0.5f,5)
{
    initTexture();
    initSprite();
}

Alien::~Alien()
{

}

Alien::Alien(sf::Vector2f pos) : Monster(2,5,0.5f,5)
{
    initTexture();
    initSprite();
    this->sprite.setPosition(pos);
}
