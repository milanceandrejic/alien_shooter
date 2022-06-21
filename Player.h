//
// Created by Milance Andrejic on 18.6.22..
//

#ifndef GAMEPROJECT_PLAYER_H
#define GAMEPROJECT_PLAYER_H

#include "Libraries.h"

class Player{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f playerCenter;

    float movementSpeed;
    float attackCoolDownMAX;
    float attackCoolDown;

    int healthMAX;
    int health;

    void initTexture();
    void initSprite();
    void initVariables();
    void initHPBar();
    void updateAttack();
    void updatePosition();

public:
    Player();
    virtual ~Player();
    void render(sf::RenderTarget &target);
    void update();

    void updateHPBar();
    sf::RectangleShape HPBar;
    sf::RectangleShape HPBarBack;

    void move(const float dirX, const float dirY);

    //Accessors
    const sf::FloatRect getBounds() const;
    const sf::Vector2f &getPosition() const;
    void setPosition(const float x, const float y);
    void setPosition(sf::Vector2f pos);
    const sf::Vector2f &getPlayerCenter() const;
    sf::Sprite &getPlayer();
    const int getHP() const;

    void loseHP(int damage);
    bool canAttack();

};


#endif //GAMEPROJECT_PLAYER_H
