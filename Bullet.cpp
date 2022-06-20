//
// Created by Milance Andrejic on 19.6.22..
//

#include "Bullet.h"

Bullet::Bullet()
{
    this->velocity = sf::Vector2f(0.0f,0.0f);
}

Bullet::Bullet(sf::Texture *texture, float pos_X, float pos_Y,float dir_X, float dir_Y, float mov_Speed)
{
    this->shape.setTexture(*texture);
    this->shape.setPosition(pos_X,pos_Y);
    this->direction.x = dir_X;
    this->direction.y =dir_Y;
    this->movSpeed = mov_Speed;
}

Bullet::~Bullet()
{

}

//------------------------------>>> Functions <<<-------------------------------\\

void Bullet::update()
{
    //Movement
    this->shape.move(this->movSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

//Accessors

const sf::FloatRect Bullet::getBounds() const {
    return this->shape.getGlobalBounds();
}