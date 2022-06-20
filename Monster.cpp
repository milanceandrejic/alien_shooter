//
// Created by Milance Andrejic on 19.6.22..
//

#include "Monster.h"
#include <math.h>

Monster::Monster()
{
    this->direction = sf::Vector2f(0.0f,0.0f);
}

Monster::~Monster()
{

}


void Monster::render(sf::RenderTarget *target)
{
    target->draw(this->sprite);
}

void Monster::update()
{
    this->sprite.move(this->direction * this->speed);
}

void Monster::initSprite()
{

}

void Monster::initTexture()
{

}

Monster::Monster(int _health, int _points, float _speed, int _damage)
{
    this->health = _health;
    this->points = _points;
    this->speed = _speed;
    this->damage = _damage;
    this->direction = sf::Vector2f(0.0f, 0.0f);
}

void Monster::updateDirection(float x, float y)
{
    this->direction.x = x;
    this->direction.y = y;
}

void Monster::updateDirection(sf::Vector2f rel)
{
    aimDir = rel - this->getPosition() - sf::Vector2f(this->sprite.getGlobalBounds().width/2.0f,
                                                              this->sprite.getGlobalBounds().height/2.0f);
    direction = aimDir / sqrt(pow(aimDir.x,2.0f) + pow(aimDir.y,2.0f));
}

const sf::Vector2f &Monster::getPosition() const
{
    return this->sprite.getPosition();
}

const sf::FloatRect Monster::getBounds() const {
    return this->sprite.getGlobalBounds();
}

const int Monster::getDamage() const
{
    return this->damage;
}

void Monster::loseHP()
{
    this->health--;
}

const int Monster::getHP() const {
    return this->health;
}
