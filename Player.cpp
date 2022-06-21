//
// Created by Milance Andrejic on 18.6.22..
//

#include "Player.h"

Player::Player()
{
    this->initTexture();
    this->initSprite();
    this->initVariables();
    this->initHPBar();
}

void Player::initTexture()
{
    if(!this->texture.loadFromFile("/Users/milanceandrejic/CLionProjects/GameProject/textures/spaceship.png"))
    {
        std::cout<< "ERROR::PLAYER::INIT_TEXTURE: Can not load texture\n";
    }
}

void Player::initSprite()
{
    //Set texture to the sprite
    this->sprite.setTexture(this->texture);
    //Resize
    this->sprite.scale(0.2f,0.2f);

    this->sprite.setPosition(640.0f - this->getBounds().width/2.0f ,480.0f - this->getBounds().height/2.0f);
}

void Player::initVariables()
{
    playerCenter.x = this->sprite.getPosition().x;
    playerCenter.y = this->sprite.getPosition().y;

    this->movementSpeed = 5.f;
    this->attackCoolDownMAX = 30.f;
    this->attackCoolDown=attackCoolDownMAX;

    this->healthMAX = 100;
    this->health = healthMAX;
}

Player::~Player()
{

}

void Player::render(sf::RenderTarget &target)
{
    target.draw(sprite);
    target.draw(HPBarBack);
    target.draw(HPBar);
}

void Player::updateAttack()
{
    if(this->attackCoolDown < this->attackCoolDownMAX)
    {
        this->attackCoolDown += 1.f;
    }
}

void Player::update()
{
    this->updatePosition();
    this->updateAttack();
    this->updateHPBar();
}

void Player::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}

const sf::FloatRect Player::getBounds() const
{
    return sprite.getGlobalBounds();
}

const sf::Vector2f &Player::getPosition() const
{
    return this->sprite.getPosition();
}

void Player::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x,y);
}

void Player::setPosition(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

bool Player::canAttack()
{
    if(this->attackCoolDown >= this->attackCoolDownMAX)
    {
        this->attackCoolDown = 0.f;
        return true;
    }
    return false;
}

const sf::Vector2f &Player::getPlayerCenter() const {
    return this->playerCenter;
}

void Player::updatePosition()
{
    this->playerCenter.x = this->sprite.getPosition().x + this->sprite.getGlobalBounds().width/2.0f;
    this->playerCenter.y = this->sprite.getPosition().y + this->sprite.getGlobalBounds().height/2.0f;
}

sf::Sprite &Player::getPlayer()
{
    return this->sprite;
}

void Player::loseHP(int damage)
{
    this->health -= damage;
}

const int Player::getHP() const
{
    return this->health;
}

void Player::initHPBar()
{
    this->HPBar.setSize(sf::Vector2f(this->getBounds().width,7.f));
    this->HPBar.setFillColor(sf::Color::Green);
    this->HPBar.setPosition(sf::Vector2f(this->getPosition().x,this->getPosition().y-15.0f));

    this->HPBarBack = this->HPBar;
    this->HPBarBack.setFillColor(sf::Color(25,25,25,200));
}

void Player::updateHPBar()
{
    float hpPercent = GetPercent(health, healthMAX);
    this->HPBar.setSize(sf::Vector2f(this->getBounds().width * hpPercent,this->HPBar.getSize().y));
    if(this->getHP() < 50)
        this->HPBar.setFillColor(sf::Color::Yellow);
    if(this->getHP() < 30)
        this->HPBar.setFillColor(sf::Color::Red);
    this->HPBar.setPosition(sf::Vector2f(this->getPosition().x,this->getPosition().y-15.0f));
    this->HPBarBack.setPosition(sf::Vector2f(this->getPosition().x,this->getPosition().y-15.0f));
}
