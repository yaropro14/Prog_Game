//
//  Drowable.hpp
//  Corovans
//
//  Created by Yaroslav on 18/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

//#include "Game.hpp"

class Game;
class Object;


#ifndef Drowable_hpp
#define Drowable_hpp

#include <stdio.h>
#include <vector>


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


enum SPRITE_TYPE
{
    CHARACTER,
    PYRAMID,
    SCELET,
    STONE,
    GREENERY,
    TREE,
    LIFE,
    BRILLIANT,
    CAMEL,
    SNAKE,
    BORDER
};


class Drawable
{
public:
    Drawable();
    ~Drawable();
    
    //sf::Sprite virtual SetSprite() = 0;
    
    Game * game;
    
    sf::Texture texture;
    sf::Sprite sprite;
};


class DrwCharacter : public Drawable
{
public:
    DrwCharacter();
    ~DrwCharacter();
    sf::Sprite SetSprite();
    
    Game * game;
    static int position[8][4];
};


class DrwSnake : public Drawable
{
public:
    DrwSnake();
    ~DrwSnake();
    sf::Sprite SetSprite(Object * o);
    
    Game * game;
};


class DrwCamel : public Drawable
{
public:
    DrwCamel();
    ~DrwCamel();
    sf::Sprite SetSprite();
    
    Game * game;
    
    int x, y;
};


class DrwObject : public Drawable
{
public:
    DrwObject();
    ~DrwObject();
    
    sf::Sprite SetSprite(SPRITE_TYPE type);
    
    Game * game;
    
    sf::Sprite sprites[7];
    sf::Texture textures[7];
};


class SistemSprites
{
public:
    SistemSprites();
    ~SistemSprites();
    
    sf::Texture t_life;
    sf::Sprite life;
    
    sf::Texture t_b_life;
    sf::Sprite b_life;
    
    sf::Texture t_num;
    sf::Sprite num;
    
    sf::Texture t_wpoint;
    sf::Sprite wpoint;
    
    sf::Texture t_bril;
    sf::Sprite bril;
    
    sf::Texture t_menu;
    sf::Sprite menu;
    
    sf::Texture t_menu2;
    sf::Sprite menu2;
    
    sf::Texture t_menu3;
    sf::Sprite menu3;
    
    sf::Texture t_menu4;
    sf::Sprite menu4;
};


class Storage
{
public:
    Storage();
    ~Storage();
    
    int num;
    
    DrwCharacter * c;
    DrwObject * so;
    DrwCamel * ca;
    DrwSnake * s;
    SistemSprites * ss;
    
    std::vector <Drawable *>  drw;
    
    sf::Sprite GetSprite(SPRITE_TYPE type, Object * o);
};

#endif /* Drowable_hpp */
