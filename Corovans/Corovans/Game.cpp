//
//  Game.cpp
//  Corovans
//
//  Created by Yaroslav on 01/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Game.hpp"


Game::Game()
{
}


void Game::CharacterPaint(CharacterPainter p)
{
    switch (character->dir) {
        case ST_BACK:
            character->sprite.setTextureRect(sf::IntRect(0, 1367, 81, 184));
            break;
            
        case ST_FORWARD:
            character->sprite.setTextureRect(sf::IntRect(182, 1367, 77, 178));
            break;
            
        case ST_LEFT:
            character->sprite.setTextureRect(sf::IntRect(104, 1367, 57, 180));
            break;
            
        case ST_RIGHT:
            character->sprite.setTextureRect(sf::IntRect(161, 1367, -57, 180));
            break;
            
        case BACK:
            character->sprite.setTextureRect(sf::IntRect(0, 1367, 81, 184));
            break;
            
        case FORWARD:
            character->sprite.setTextureRect(sf::IntRect(182, 1367, 77, 178));
            break;
            
        case LEFT:
            character->sprite.setTextureRect(sf::IntRect(104, 1367, 57, 180));
            break;
            
        case RIGHT:
            character->sprite.setTextureRect(sf::IntRect(161, 1367, -57, 180));
            break;
            
            
        default:
            break;
    }
    
    p(character->sprite, character->body.front(), character->height);
}


void Game::CamelPaint(CamelPainter p)
{
    //for(const auto & s : camels) {
    //for(const auto & c : s.body) {
    // addin camel at the map !!!!
    //}
    //cp(s.body.front(), s.dir);
    //}
}

void Game::ObjectsPaint(ObjectPainter p)
{
    for(auto s : objects)
        p(*s);
}

void Game::AddObject(Object * o)
{
    objects.push_back(o);
}

Game * Game::inst;

Game * Game::Get()
{
    if(inst != nullptr)    return Game::inst;
    Game::inst = new Game;
    return Game::inst;
}


void Game::Move()
{
    character->Move();
}


Game::~Game()
{
}


Character::Character()
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/HumanRun.png");
    sprite.setTexture(texture);
    
    height = 175;
    
    //std::list <Coord> position;
    
    dir = ST_FORWARD;
    step = 0;
    
    Coord c {2, 7};
    
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 5; j ++)
            body.push_back(Coord(c.first + j, c.second + i));
    
}


void Character::SetDirection(Dir d)
{
    dir = d;
}


void Character::Move()
{
    switch (dir) {
        case FORWARD:
            body = ChangePosition(body, 0, -1);
            dir = ST_FORWARD;
            break;
            
        case BACK:
            body = ChangePosition(body, 0, 1);
            dir = ST_BACK;
            break;
            
        case LEFT:
            body = ChangePosition(body, -1, 0);
            dir = ST_LEFT;
            break;
            
        case RIGHT:
            body = ChangePosition(body, 1, 0);
            dir = ST_RIGHT;
            break;
            
        default:
            break;
            
    }
}


std::list <Coord> ChangePosition(std::list <Coord> body, int x, int y)
{
    int n = (int) body.size();
    
    for(int i = 0; i < n; i++) {
        
        //printf("i = %d \n", i);
        
        //int o = 0;
        //scanf("%d", &o);
        
        if(i > n)
        {
            break;
        }
        
        Coord n = body.front();
        body.pop_front();
        n.first += x;
        n.second += y;
        body.push_back(n);
    }
    
    return body;
}


Character::~Character()
{
}


Camel::Camel(Coord c)
{
    /*
    if(c.first < 2) {
        c.first = 2;
    }
    
    if(c.first > -4) {
        c.first = -4;
    }
    */
    dir = R;
    for(int i = c.first; i <= c.first + 3; i++)
        for(int j = c.second; j <= c.second + 4; j++)
            body.push_back(Coord(j, i));
    
}


Camel::Camel()
{
    //camel_texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Camel.png");
    //camel.setTexture(camel_texture);
}


Camel::~Camel()
{
}
