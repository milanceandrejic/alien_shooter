//
// Created by Milance Andrejic on 19.6.22..
//

#ifndef GAMEPROJECT_LIBRARIES_H
#define GAMEPROJECT_LIBRARIES_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Player.h"
#include "Bullet.h"

template <typename T>
float GetPercent(T value, T maxValue)
{
    return 1.0f*value/maxValue;
};

template <typename T>
void ExchangeValues(T& t1, T& t2)
{
    T tmp = t2;
    t2 = t1;
    t1 = tmp;
};



#endif //GAMEPROJECT_LIBRARIES_H
