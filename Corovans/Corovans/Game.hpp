//
//  Game.hpp
//  Corovans
//
//  Created by Yaroslav on 01/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//
#ifndef Game_hpp
#define Game_hpp


#include <stdio.h>
#include <list>


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Sound.hpp"

class SnakeAI;


const int CELL_SIZE = 1;
const int NUM_LIFES = 50;


enum OBJ
{
    HEROE,
    OBJECT,
    BORT,
    CAM,
    FREE
};



const int X_SIZE = 6630;
const int Y_SIZE = 3770;


using CamelPainter = std::function<void(Coord, L_R_Dir)>;
using ObjectPainter = std::function<void(SPRITE_TYPE, Coord, int, Object *)>;
using SnakePainter = std::function<void(SPRITE_TYPE, Coord, int, Object *)>;
using MapPainter = std::function<void(sf::Sprite &, Coord)>;


class Map
{
public:
    Map();
    ~Map();
    
    int x_size, y_size;
    
    sf::Texture background;
    sf::Sprite sand;
    sf::Sprite stone;
    int size_in_cell;
};


class Alive
{
public:
    Alive();
    ~Alive();
    int lifes;
};


class LeftRightDirection
{
public:
    LeftRightDirection();
    ~LeftRightDirection();
    
    //virtual void Move() = 0;
    
    L_R_Dir d;
    
    void SetDirection(L_R_Dir d)
    {
        d = d;
    }
    
};


class Camel : public Object, public LeftRightDirection
{
public:
    Camel(Coord c, L_R_Dir dir);
    Camel();
    ~Camel();
    
    int full;
    
    void Move();
    OBJ CheckPosition(Coord c);
    
    //int step;
};


class Corovan : public LeftRightDirection
{
public:
    Corovan();
    ~Corovan();
    
    Coord position;
    int step;
    
    std::list<Camel *> camels;
    
    bool complite;
    
    Figure figure;

    void Move();
    
    bool CheckYPosition(int y, int y_size);
};


class Snake : public Object, public Alive
{
public:
    Snake();
    Snake(Coord c);
    ~Snake();
    
    //Dir dir;
    int speed;
    bool bite;
    int lifes;
    
    void Move();
    Coord NextPosition();
    SPRITE_TYPE CheckPosition(Coord c);
};


class Character : public Object, Alive
{
public:
    Character();
    ~Character();
    
    Character(const Character & c):
    dir(c.dir), step(c.step),
    speed(c.speed)
    {}
    
    Character & operator = (const Character & c){
        dir = c.dir;
        step = c.step;
        position = c.position;
        speed = c.speed;
        return * this;
    }
    
    void Move();
    bool SetDirection(Dir d);
    void Hurm();
    SPRITE_TYPE CheckPosition(Coord c);
    
    int lifes;
    int brilliants;
    
    bool go;
    bool hit;
    bool rob;
    
    bool hurm;
    Dir hurm_dir;

    Dir dir;
    int step;
    int speed;
};


class Game {
public:
    static Game * inst;
    
    Game();
    ~Game();
    
    static Game * Get();
    
    std::list <SnakeAI *> snake_Ai_deligater;
    void SetOnSnakeAI(SnakeAI * s)
    {
        snake_Ai_deligater.push_back(s);
    }
    
    Sounds * sounds;
    
    void SetSound(Sounds * s)
    {
        sounds = s;
    }
    
    Character * character;
    Map * map;
    Corovan * corovan;
    std::list <Object *> objects;
    
    void CreateField();
    Coord GetCoordForObject(int n, int dx, int dy);
    bool CheckPlace(Coord c, int radius);
    bool OnSkreen(int x, int y);
    void SnakePaint(Object * o, SnakePainter p);
    void ObjectsPaint(Object * o, ObjectPainter p);
    void MapPaint(MapPainter p, Coord c);
    
    void Move();
    void NewLife();
    
    void AddObject(Object * o);
};


bool Check(Coord a, Coord b, int a_x, int a_y, int b_x, int b_y);


Coord ChangePosition(Coord position, int x, int y);


#endif /* Game_hpp */
