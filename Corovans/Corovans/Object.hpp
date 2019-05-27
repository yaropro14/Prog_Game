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
#include <iostream>
#include <cstdlib>


#include "Storage.hpp"
#include "Figure.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


enum L_R_Dir
{
    R,
    L,
    N
};

enum Dir
{
    ST_BACK,
    ST_FORWARD,
    ST_LEFT,
    ST_RIGHT,
    BACK,
    FORWARD,
    LEFT,
    RIGHT,
    NO
};


class Object
{
public:
    Object();
    ~Object();
    
    Coord position;
    
    unsigned int x_size;
    unsigned int y_size;
    unsigned int z_size;
    
    SPRITE_TYPE type;
    int step;
    Dir dir;
    
    Figure figure;
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


class Life : public Object
{
public:
    Life(Coord c);
    ~Life();
};


class Brilliant : public Object
{
public:
    Brilliant(Coord c);
    ~Brilliant();
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
