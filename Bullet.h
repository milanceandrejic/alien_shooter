//
// Created by Milance Andrejic on 19.6.22..
//

#ifndef GAMEPROJECT_BULLET_H
#define GAMEPROJECT_BULLET_H
#include "Player.h"

class Bullet{
private:
    sf::Sprite shape;

    sf::Vector2f direction;
    float movSpeed;
    sf::Vector2f velocity;

    //Private functions

public:
    //Cons / Des
    Bullet();
    Bullet(sf::Texture *texture, float pos_X, float pos_Y, float dir_X, float dir_Y, float mov_Speed);
    virtual ~Bullet();

    //Accessors
    const sf::FloatRect getBounds() const;

    //Functions
    void update();
    void render(sf::RenderTarget *target);

};


#endif //GAMEPROJECT_BULLET_H
