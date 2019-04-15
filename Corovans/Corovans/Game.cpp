//
//  Game.cpp
//  Corovans
//
//  Created by Yaroslav on 01/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Game.hpp"
#include "View.hpp"


Game::Game()
{
    map = new Map();
}


void Game::CharacterPaint(CharacterPainter p)
{
    switch (character->dir) {
        case ST_BACK:
            character->sprite.setTextureRect(sf::IntRect(10, 595, 86, 195));
            break;
            
        case ST_FORWARD:
            character->sprite.setTextureRect(sf::IntRect(194, 595, 78, 178));
            break;
            
        case ST_LEFT:
            character->sprite.setTextureRect(sf::IntRect(115, 595, 60, 180));
            break;
            
        case ST_RIGHT:
            character->sprite.setTextureRect(sf::IntRect(175, 595, -60, 180));
            break;
            
        case BACK:
            character->sprite.setTextureRect(sf::IntRect(100 * character->step, 0, 100, 190));
            break;
            
        case FORWARD:
            character->sprite.setTextureRect(sf::IntRect(100 * character->step, 205, 100, 187));
            break;
            
        case LEFT:
            character->sprite.setTextureRect(sf::IntRect(100 * character->step, 394, 100, 183));
            break;
            
        case RIGHT:
            character->sprite.setTextureRect(sf::IntRect(100 * (character->step + 1), 394, -100, 183));
            break;
            
            
        default:
            break;
    }
    
    p(character->sprite, character->position, character->z_size);
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

void Game::ObjectsPaint(Object * o ,ObjectPainter p)
{
        p(o->sprite, o->position, o->z_size);
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


void Game::MapPaint(MapPainter p, Coord c)
{
    for(int y = c.second, j = 0; j < map->y_size; y += map->size_in_cell, j+= map->size_in_cell)
        for(int x = c.first, i = 0; i < map->y_size; x += map->size_in_cell, i+= map->size_in_cell){
            if(y == 0 || x == 0)
                p(map->stone, Coord(i, j));
            //else if(y >= Y_SIZE - 170 || x >= X_SIZE - 170)
                //p(map->stone, Coord(i, j));
            else
                p(map->sand, Coord(i, j));;
        }
}


Game::~Game()
{
}


Character::Character()
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/HumanRun.png");
    sprite.setTexture(texture);
    
    z_size = 182 / CELL_SIZE;
    x_size = 100 / CELL_SIZE;
    y_size = 90 / CELL_SIZE;
    
    //std::list <Coord> position;
    
    dir = ST_BACK;
    step = 0;
    speed = 10;
    
    Game * g =  Game::Get();
    
    position.first = g->map->size_in_cell;
    position.second = g->map->size_in_cell + z_size;
    
}


void Character::SetDirection(Dir d)
{
    if(dir != d)    step = 0;
    /*
    if(d == NO) {
        switch (dir) {
            case BACK:
                dir = ST_BACK;
                break;
                
            case LEFT:
                dir = ST_LEFT;
                break;
                
            case FORWARD:
                dir = ST_FORWARD;
                break;
                
            case RIGHT:
                dir = ST_RIGHT;
                break;
                
            default:
                break;
        }
    }*/
    
    dir = d;
}


void Character::Move()
{
    switch (dir) {
        case FORWARD:
            position = ChangePosition(position, 0, -speed);
            step ++;
            step = step % 8;
            dir = FORWARD;
            break;
            
        case BACK:
            position = ChangePosition(position, 0, speed);
            step ++;
            step = step % 8;
            dir = BACK;
            break;
            
        case LEFT:
            position = ChangePosition(position, -speed, 0);
            step ++;
            step = step % 8;
            dir = LEFT;
            break;
            
        case RIGHT:
            position = ChangePosition(position, speed, 0);
            step ++;
            step = step % 8;
            dir = RIGHT;
            break;
            
        default:
            break;
            
    }
}


Coord ChangePosition(Coord position, int x, int y)
{
    position.first += x;
    position.second += y;
    
    return position;
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


Map::Map()
{
    x_size = X_SIZE;
    y_size = Y_SIZE;
    
    background.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Bacground.png");
    sand.setTexture(background);
    sand.setTextureRect(sf::IntRect(0, 0, 70, 70));
    
    stone.setTexture(background);
    stone.setTextureRect(sf::IntRect(70, 0, 70, 70));
    
    sf::Vector2u size = background.getSize();
    
    size_in_cell = size.y / CELL_SIZE;//View::Get()->cell_size;
}

Map::~Map()
{
}
