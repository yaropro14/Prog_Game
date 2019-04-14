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


enum L_R_Dir
{
    R,
    L,
    N
};

enum Dir
{
    RIGHT,
    LEFT,
    FORWARD,
    BACK,
    ST_RIGHT,
    ST_LEFT,
    ST_FORWARD,
    ST_BACK,
    NO
};


using Coord = std::pair <int, int>;


using CharacterPainter = std::function<void(sf::Sprite, Coord, int)>;
using CamelPainter = std::function<void(Coord, L_R_Dir)>;
using ObjectPainter = std::function<void(Object)>;


class Camel
{
public:
    Camel(Coord c);
    Camel();
    ~Camel();
    sf::Texture texture;
    sf::Sprite sprite;
    std::list <Coord> body;
    L_R_Dir dir;
};

/*
class
public:
    Camel(Coord c);
    Camel();
    ~Camel();
    sf::Texture texture;
    sf::Sprite sprite;
    std::list <Coord> body;
    L_R_Dir dir;
};
*/

class Character
{
public:
    Character();
    ~Character();
    
    Character(const Character & c):
    dir(c.dir), body(c.body), texture(c.texture),
    sprite(c.sprite), step(c.step), height(c.height)//, \
    position(c.position)
    {}
    
    Character & operator = (const Character & c){
        dir = c.dir;
        body = c.body;
        texture = c.texture;
        sprite = c.sprite;
        step = c.step;
        height = c.height;
        //position = c.position;
        return * this;
    }
    
    void Move();
    void SetDirection(Dir d);
    
    sf::Texture texture;
    sf::Sprite sprite;
    unsigned int height;
    
    std::list <Coord> body;
    //Coord & position;
    Dir dir;
    int step;
};


class Game {
public:
    static Game * inst;
    
    Game();
    ~Game();
    
    static Game * Get();
    
    Character * character;
    
    std::list <Object *> objects;
    
    void CharacterPaint(CharacterPainter p);
    void CamelPaint(CamelPainter p);
    void ObjectsPaint(ObjectPainter p);
    
    void Move();
    
    void AddObject(Object * o);
};


std::list <Coord> ChangePosition(std::list <Coord> body, int x, int y);


#endif /* Game_hpp */
