//
//  ActiveObjects.hpp
//  Corovans
//
//  Created by Yaroslav on 11/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef ActiveObjects_hpp
#define ActiveObjects_hpp


#include <stdio.h>
#include <list>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Game.hpp"


class ActiveObjects
{
public:
    ActiveObjects();
    ~ActiveObjects();
    
    sf::Texture texture;
    sf::Sprite sprite;
    std::list <Coord> body;
};


class Coconut : public ActiveObjects
{
    Coconut(Coord c);
    ~Coconut();
};


class Banana : public ActiveObjects
{
    Banana(Coord c);
    ~Banana();
};


class Palm : public ActiveObjects
{
public:
    Palm(Coord c);
    ~Palm();
    
    Banana * banana;
};


class Palm2 : public ActiveObjects
{
public:
    Palm2(Coord C);
    ~Palm2();
    
    Coconut * coconat;
};


#endif /* ActiveObjects_hpp */
