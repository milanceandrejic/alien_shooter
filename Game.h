//
// Created by Milance Andrejic on 18.6.22..
//

#ifndef GAMEPROJECT_GAME_H
#define GAMEPROJECT_GAME_H

#include "Player.h"
#include "Libraries.h"
#include "Alien.h"
#include "BugAlien.h"
#include "FireAlien.h"
#include <map>


class Game{
private:
    //Window
    sf::RenderWindow* window;
    sf::Vector2f mousePos;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    //Player
    Player *player;
    std::vector<Bullet*> bullets;
    std::vector<Bullet*> enemyBullets;

    //Enemies
    float spawnTimer;
    float spawnTimerMAX;
    std::vector<Monster*> enemies;

    //World
    sf::Texture worldBackTex;
    sf::Sprite worldBackground;

    //Resources
    std::map<std::string ,sf::Texture*> textures;

    //Private functions
    void updatePollEvents();
    void initVariables();
    void initWindow();
    void initTextures();
    void initEnemies();
    void initWorld();
    void renderWorld();

    void updateInput();
    void updateBorderCollision();
    void updateBullets();
    void updateEnemyBullets();

public:
    Game();
    virtual ~Game();
    void run();
    void update();
    void render();
    void updateEnemies();
    void updateCombat();

};


#endif //GAMEPROJECT_GAME_H
