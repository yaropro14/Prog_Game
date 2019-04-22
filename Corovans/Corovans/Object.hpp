//
//  NotMovebleObjects.hpp
//  Corovans
//
//  Created by Yaroslav on 09/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef Objects_hpp
#define Objects_hpp

#include <stdio.h>
#include <list>
#include "Storage.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


using Coord = std::pair <int, int>;

class Object
{
public:
    Object();
    ~Object();
    
    sf::Texture texture;
    sf::Sprite sprite;
    
    Coord position;
    
    unsigned int x_size;
    unsigned int y_size;
    unsigned int z_size;
    
    SPRITE_TYPE type;
};

class Pyramid : public Object
{
public:
    Pyramid(Coord c);
    ~Pyramid();
};

class Scelet : public Object
{
public:
    Scelet(Coord c);
    ~Scelet();
};

class Stone : public Object
{
public:
    Stone(Coord c);
    ~Stone();
};

class Greenery : public Object
{
public:
    Greenery(Coord c);
    ~Greenery();
};

class Tree : public Object
{
public:
    Tree(Coord c);
    ~Tree();
};

#endif /* Objects_hpp */
