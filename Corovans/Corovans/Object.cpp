//
//  NotMovebleObjects.cpp
//  Corovans
//
//  Created by Yaroslav on 09/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Object.hpp"
#include "Game.hpp"


Object::Object()
{
}

Object::~Object()
{
}

Pyramid::Pyramid(Coord c)
{
    x_size = 316 / CELL_SIZE;
    y_size = 190 / CELL_SIZE;
    z_size = 296 / CELL_SIZE;
    
    type = PYRAMID;
    
    position = c;
    
    figure.position.first = -8;
    figure.position.second = -15;

    figure.x = 330;
    figure.y = 165;
}

Pyramid::~Pyramid()
{
    
}

Scelet::Scelet(Coord c)
{
    x_size =  78 / CELL_SIZE;
    y_size =  78 / CELL_SIZE;
    z_size =  91 / CELL_SIZE;
    
    type = SCELET;
    
    position = c;
    
    figure.position.first = 0;
    figure.position.second = 0;
    
    figure.x = 56;
    figure.y = 56;
}

Scelet::~Scelet()
{
    
}

Stone::Stone(Coord c)
{
    x_size =  65 / CELL_SIZE;
    y_size =  65 / CELL_SIZE;
    z_size =  52 / CELL_SIZE;
    
    type = STONE;
    
    position = c;
    
    figure.position.first = 0;
    figure.position.second = 0;
    
    figure.x = 40;
    figure.y = 30;
}

Stone::~Stone()
{
    
}


Life::Life(Coord c)
{
    x_size =  25 / CELL_SIZE;
    y_size =  25 / CELL_SIZE;
    z_size =  81 / CELL_SIZE;
    
    type = LIFE;
    
    position = c;
    
    figure.position.first = 10;
    figure.position.second = 0;
    
    figure.x = 25;
    figure.y = 25;
}

Life::~Life()
{
    
}


Greenery::Greenery(Coord c)
{
    x_size =  80 / CELL_SIZE;
    y_size =  50 / CELL_SIZE;
    z_size =  286 / CELL_SIZE;
    
    type = GREENERY;
    
    position = c;
    
    figure.position.first = 0;
    figure.position.second = -6;
    
    figure.x = 80;
    figure.y = 15;
}

Greenery::~Greenery()
{
    
}

Tree::Tree(Coord c)
{
    x_size =  91 / CELL_SIZE;
    y_size =  91 / CELL_SIZE;
    z_size =  338 / CELL_SIZE;
    
    type = TREE;
    
    position = c;
    
    figure.position.first = 90;
    figure.position.second = 0;
    
    figure.x = 80;
    figure.y = 16;
}

Tree::~Tree()
{
    
}



Brilliant::Brilliant(Coord c)
{
    x_size =  60 / CELL_SIZE;
    y_size =  10 / CELL_SIZE;
    z_size =  62 / CELL_SIZE;
    
    type = BRILLIANT;
    
    position = c;
    
    figure.position.first = 5;
    figure.position.second = 0;
    
    figure.x = 30;
    figure.y = 30;
}

Brilliant::~Brilliant()
{
    
}
