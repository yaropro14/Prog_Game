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
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Pyramid.png");
    sprite.setTexture(texture);
    
    x_size =  299 / CELL_SIZE;
    y_size =  299 / CELL_SIZE;
    z_size =  260 / CELL_SIZE;
    
    position = c;
    
}

Pyramid::~Pyramid()
{
    
}

Scelet::Scelet(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Scelet.png");
    sprite.setTexture(texture);
    
    x_size =  78 / CELL_SIZE;
    y_size =  78 / CELL_SIZE;
    z_size =  91 / CELL_SIZE;
    
    position = c;
}

Scelet::~Scelet()
{
    
}

Stone::Stone(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/S_stone.png");
    sprite.setTexture(texture);
    
    x_size =  65 / CELL_SIZE;
    y_size =  65 / CELL_SIZE;
    z_size =  52 / CELL_SIZE;
    
    position = c;
}

Stone::~Stone()
{
    
}

Greenery::Greenery(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Greenery.png");
    sprite.setTexture(texture);

    x_size =  104 / CELL_SIZE;
    y_size =  309 / CELL_SIZE;
    z_size =  286 / CELL_SIZE;
    
    position = c;
}

Greenery::~Greenery()
{
    
}

Tree::Tree(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/DryTree.png");
    sprite.setTexture(texture);
    
    x_size =  91 / CELL_SIZE;
    y_size =  91 / CELL_SIZE;
    z_size =  338 / CELL_SIZE;
    
    position = c;
}

Tree::~Tree()
{
    
}
