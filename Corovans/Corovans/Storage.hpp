//
//  Drowable.hpp
//  Corovans
//
//  Created by Yaroslav on 18/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

//#include "Game.hpp"

class Game;

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
    TREE
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


class DrwObject : public Drawable
{
public:
    DrwObject();
    ~DrwObject();
    
    sf::Sprite SetSprite(SPRITE_TYPE type);
    
    Game * game;
    
    sf::Sprite sprites[5];
    sf::Texture textures[5];
};


class Storage
{
public:
    Storage();
    ~Storage();
    
    int num;
    
    DrwCharacter * c;
    DrwObject * o;
    
    std::vector <Drawable *>  drw;
    
    sf::Sprite GetSprite(SPRITE_TYPE type);
    
};

#endif /* Drowable_hpp */
