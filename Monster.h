//
// Created by Milance Andrejic on 19.6.22..
//

#ifndef GAMEPROJECT_MONSTER_H
#define GAMEPROJECT_MONSTER_H
#include "Libraries.h"

class Monster{

protected:
    int health;
    int healthMAX;
    sf::Sprite sprite;
    sf::Texture texture;

    sf::Vector2f direction;

    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    float attackCoolDownMAX;
    float attackCoolDown;

    int damage;
    int points;
    float speed;

    sf::RectangleShape HPBar;
    sf::RectangleShape HPBarBack;

    virtual void initTexture();
    virtual void initSprite();
    virtual void updateAttack();

public:
    Monster();
    Monster(int _health, int _points, float _speed, int _damage);
    virtual ~Monster();

    virtual void update();
    virtual void attack(std::vector<Bullet*> &_enemy_bullets);
    virtual void render(sf::RenderTarget* target);
    virtual void updateDirection(float x, float y);
    virtual void updateDirection(sf::Vector2f rel);
    const sf::Vector2f &getPosition() const;
    const sf::FloatRect getBounds() const;
    const int getDamage() const;
    const int getHP() const;

    void loseHP();

    void initHPBar();
    void updateHPBar();

    virtual bool canAttack();
};


#endif //GAMEPROJECT_MONSTER_H
