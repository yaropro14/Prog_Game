//
//  Game.cpp
//  Corovans
//
//  Created by Yaroslav on 01/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Game.hpp"
#include "View.hpp"
//#include "Storage.hpp"


Game::Game()
{
    map = new Map();
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
    for(auto * o : objects)
        p(o->type, o->position, o->z_size);
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
    for(int y  = 0; y < Y_SIZE; y += map->size_in_cell) {
        if(y + map->size_in_cell >= c.second)
            for(int x = 0; x < X_SIZE; x += map->size_in_cell){
                if(x + map->size_in_cell >= c.first) {
                    if(y == 0 || x == 0)
                        p(map->stone, Coord(x, y));
                    else if(y >= Y_SIZE - 75 || x >= X_SIZE - 70)
                        p(map->stone, Coord(x, y));
                    else
                        p(map->sand, Coord(x, y));;
                }
        }
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
    dir = d;
}

bool Check(Coord a, Coord b, int a_x, int b_x, int a_y, int b_y)
{
    if(a.first + a_x >= b.first && a.first + a_x <= b.first + b_x)
    {
        if(a.second >= b.second && b.second - b_y <= a.second)  return true;
        if(a.second - a_y >= b.second && b.second - b_y <= a.second - a_y) return true;
        //return true;
    }
    
    if(b.first <= a.first && b.first + b_x >= a.first)
    {
        if(a.second >= b.second && b.second - b_y <= a.second)  return true;
        if(a.second - a_y >= b.second && b.second - b_y <= a.second - a_y) return true;
        //return true;
    }
//
    
    printf("%d %d\n", a.first, a.second);
    //printf("%d %d\n", a_y, b_y);
    
    return false;
}


char Character::CheckPosition(Coord c)
{
    
    for(auto o : Game::Get()->objects)
    {
        if(Check(c, o->position, x_size, o->x_size, y_size, o->y_size))    return 'o';
    }
    
    return ' ';
}


void Character::Move()
{
    
    switch (dir) {
        case FORWARD:
//            if(CheckPosition(ChangePosition(position, 0, -speed)) == 'o') {}
            position = ChangePosition(position, 0, -speed);
            step ++;
            step = step % 8;
            dir = FORWARD;
            break;
            
        case BACK:
//            if(CheckPosition(ChangePosition(position, 0, speed)) == 'o') {}
            position = ChangePosition(position, 0, speed);
            step ++;
            step = step % 8;
            dir = BACK;
            break;
            
        case LEFT:
//            if(CheckPosition(ChangePosition(position, -speed, 0)) == 'o') {}
            position = ChangePosition(position, -speed, 0);
            step ++;
            step = step % 8;
            dir = LEFT;
            break;
            
        case RIGHT:
//            if(CheckPosition(ChangePosition(position, speed, 0)) == 'o') {}
            position = ChangePosition(position, speed, 0);
            step ++;
            step = step % 8;
            if(step == 0)   step++;
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
