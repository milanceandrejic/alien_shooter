//
// Created by Milance Andrejic on 18.6.22..
//

#include "Game.h"
#include <math.h>

void Game::run()
{
    //Game loop(check poll, update and draw)
    while (this->window->isOpen())
    {
        this->updatePollEvents();

        if(this->player->getHP() > 0)
        {
            this->update();
        }
        this->render();
    }
}

void Game::update()
{
    updateInput();
    updateBorderCollision();
    this->player->update();

    mousePos.x = sf::Mouse::getPosition(*window).x;
    mousePos.y = sf::Mouse::getPosition(*window).y;

    aimDir = mousePos - player->getPlayerCenter();
    aimDirNorm = aimDir / sqrt(pow(aimDir.x,2.0f) + pow(aimDir.y,2.0f));

    updateEnemies();

    updateBullets();

    updateEnemyBullets();

    updateCombat();
}

void Game::updatePollEvents()
{
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if(e.Event::type == sf::Event::Closed)
            this->window->close();

        if(e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this->window->close();

    }
}

void Game::render()
{

    this->window->clear();

    this->renderWorld();

    this->player->render(*this->window);

    for (auto *enemy : this->enemies)
    {
        enemy->render(this->window);
    }

    for (auto *bullet : this->bullets)
    {
        bullet->render(this->window);
    }

    for (auto *bullet : this->enemyBullets)
    {
        bullet->render(this->window);
    }

    this->window->display();
}

Game::Game()
{
    this->initWorld();
    this->player = new Player();
    this->initEnemies();
    this->initWindow();
    this->initTextures();
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280,960),
                                        "Alien shooter",sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);
}

void Game::updateInput()
{
    //Move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f,1.f);

    //Fire
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && this->player->canAttack())
    {
        this->bullets.push_back(new Bullet(this->textures["BULLET"],
                                           this->player->getPlayerCenter().x,
                                           this->player->getPlayerCenter().y-20.f,
                                           aimDirNorm.x,aimDirNorm.y,5.f));
    }

}

void Game::updateBorderCollision()
{
    //left
    if(this->player->getBounds().left < 0.f)
    {
        this->player->setPosition(0.f, this->player->getBounds().top);
    }
        //right
    else if(this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
    {
        this->player->setPosition(this->window->getSize().x - this->player->getBounds().width,
                                 this->player->getBounds().top);
    }
    //top
    if(this->player->getBounds().top < 0.f)
    {
        this->player->setPosition(this->player->getBounds().left, 0.f);
    }
        //bottom
    else if(this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
    {
        this->player->setPosition(this->player->getPosition().x,
                                  this->window->getSize().y - this->player->getBounds().height);
    }
}

void Game::initTextures()
{
    this->textures["BULLET"] = new sf::Texture;
    this->textures["BULLET"]->loadFromFile("/Users/milanceandrejic/CLionProjects/GameProject/textures/bulet2.png");
}

void Game::updateBullets()
{
    unsigned counter=0;
    for (auto *bullet : this->bullets)
    {
        bullet->update();

        //Bullet culling
        if( (bullet->getBounds().top + bullet->getBounds().height < 0.f) ||
                (bullet->getBounds().top > this->window->getSize().y) ||
                (bullet->getBounds().left + bullet->getBounds().width < 0.f) ||
                (bullet->getBounds().left > this->window->getSize().x)
        )
        {
            //Bullet delete
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            --counter;
        }
        ++counter;
    }
}

void Game::updateEnemyBullets()
{
    unsigned counter=0;
    for (auto *bullet : this->enemyBullets)
    {
        bullet->update();

        //Bullet culling
        if( (bullet->getBounds().top + bullet->getBounds().height < 0.f) ||
                (bullet->getBounds().top > this->window->getSize().y) ||
                (bullet->getBounds().left + bullet->getBounds().width < 0.f) ||
                (bullet->getBounds().left > this->window->getSize().x)
        )
        {
            //Bullet delete
            delete this->enemyBullets.at(counter);
            this->enemyBullets.erase(this->enemyBullets.begin() + counter);
            --counter;
        }
        ++counter;
    }
}

void Game::initVariables()
{
    this->mousePos = sf::Vector2f(0.f,0.f);
}

Game::~Game()
{
    delete this->window;
    delete this->player;
    //Deleting textures
    for (auto &i :this->textures)
    {
        delete i.second;
    }
    //Deleting bullets
    for (auto *i :this->bullets)
    {
        delete i;
    }
    for (auto *i :this->enemyBullets)
    {
        delete i;
    }

}

void Game::initWorld()
{
    if(!this->worldBackTex.loadFromFile("/Users/milanceandrejic/CLionProjects/GameProject/textures/back.jpeg"))
        std::cerr << "\nERROR::GAME::Could not load background texture\n";
    this->worldBackground.setTexture(this->worldBackTex);
}

void Game::renderWorld()
{
    this->window->draw(this->worldBackground);
}

void Game::updateEnemies()
{
    //Spawning
    sf::Vector2f vectorPos;
    switch (rand()%5)
    {
        case 0:
            vectorPos = sf::Vector2f(-80.f,rand()%this->window->getSize().y);
            break;
        case 1:
            vectorPos = sf::Vector2f(this->window->getSize().x + 80.0f,rand()%this->window->getSize().y);
            break;
        case 2:
            vectorPos = sf::Vector2f(rand()%this->window->getSize().x,-80.0f);
            break;
        default:
            vectorPos = sf::Vector2f(rand()%this->window->getSize().x,this->window->getSize().y + 80.0);
            break;
    }
    this->spawnTimer += 1.f;
    if(this->spawnTimer >= spawnTimerMAX)
    {
        if(rand() % 3 == 0)
        {
            this->enemies.push_back(new BugAlien(vectorPos));
        }
        else if(rand() % 10 == 0)
        {
           this->enemies.push_back(new FireAlien(vectorPos));
        }
        else
        {
            this->enemies.push_back(new Alien(vectorPos));
        }
        this->spawnTimer = 0.f;
    }

    //update
    unsigned counter=0;
    for (auto *enemy : this->enemies)
    {
        for(Monster *fireAlien:this->enemies)
            fireAlien->attack(this->enemyBullets);

        enemy->updateDirection(player->getPosition());
        enemy->update();

        //Bullet culling
        if( enemy->getBounds().top > this->window->getSize().y )
        {
            //Enemy delete
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
        }
            //Enemy player collision
        else if(enemy->getBounds().intersects(this->player->getBounds()))
        {
            //Enemy delete on collision with player
            this->player->loseHP(this->enemies.at(counter)->getDamage());

            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
        }
        ++counter;
    }

}

void Game::initEnemies()
{
    this->spawnTimerMAX = 100.f;
    this->spawnTimer = spawnTimerMAX;
}

void Game::updateCombat() {
    for (int i = 0; i < this->enemies.size(); ++i)
    {
        bool enemy_deleted = false;
        for (int j = 0; j < this->bullets.size() && enemy_deleted == false; ++j)
        {
            if(this->enemies[i]->getBounds().intersects(this->bullets[j]->getBounds()))
            {
                //points += this->enemies[i]->getPoints();
                enemies[i]->loseHP();
                if(enemies[i]->getHP() < 1)
                {
                    delete this->enemies[i];
                    this->enemies.erase(this->enemies.begin() + i);
                    enemy_deleted = true;
                }
                delete this->bullets[j];
                this->bullets.erase(this->bullets.begin() + j);

            }
        }
    }
    //Checkin enemyBullets
    for (int j = 0; j < this->enemyBullets.size() ; ++j)
    {
        if(this->player->getBounds().intersects(this->enemyBullets[j]->getBounds()))
        {
            player->loseHP(3);

            delete this->enemyBullets[j];
            this->enemyBullets.erase(this->enemyBullets.begin() + j);
        }
    }

}
