//
//  NotMovebleObjects.cpp
//  Corovans
//
//  Created by Yaroslav on 09/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Object.hpp"


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
    
    for(int j = 0; j < 10; j ++)
        for(int i = 0; i < 8; i ++)
            body.push_back(Coord(c.first + i, c.second + j));
}

Pyramid::~Pyramid()
{
    
}

Scelet::Scelet(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Scelet.png");
    sprite.setTexture(texture);
    
    for(int j = 0; j < 4; j ++)
        for(int i = 0; i < 6; i ++)
            body.push_back(Coord(c.first + i, c.second + j));
}

Scelet::~Scelet()
{
    
}

Stone::Stone(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/S_stone.png");
    sprite.setTexture(texture);
    
    for(int i = 0; i < 4; i ++)
        body.push_back(Coord(c.first + i, c.second));
}

Stone::~Stone()
{
    
}

Greenery::Greenery(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Greenery.png");
    sprite.setTexture(texture);

    body.push_back(Coord(c.first, c.second));
}

Greenery::~Greenery()
{
    
}

Tree::Tree(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/DryTree.png");
    sprite.setTexture(texture);
    
    for(int j = 0; j < 4; j ++)
        for(int i = 0; i < 6; i ++)
            body.push_back(Coord(c.first + i, c.second + j));
}

Tree::~Tree()
{
    
}
