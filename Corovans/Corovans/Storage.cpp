//
//  Drowable.cpp
//  Corovans
//
//  Created by Yaroslav on 18/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//


#include "Storage.hpp"
#include "Game.hpp"


#define POSITION(DIR)                   \
    position[DIR][0],position[DIR][1],  \
    position[DIR][2],position[DIR][3]

#define POSITION_GO(DIR)                                        \
(position[DIR][0] * game->character->step),position[DIR][1],    \
position[DIR][2],position[DIR][3]



Storage::Storage()
{
    num = 0;
    c = new DrwCharacter();
    o = new DrwObject();
    //drw[num++] = new DrwCharacter();
}


Storage::~Storage()
{
}

sf::Sprite Storage::GetSprite(SPRITE_TYPE type)
{
    switch (type) {
        case CHARACTER:
            return c->SetSprite();
            break;
            
        case GREENERY:
            return o->SetSprite(GREENERY);
            
        case SCELET:
            return o->SetSprite(SCELET);
            
        case TREE:
            return o->SetSprite(TREE);
            
        case STONE:
            return o->SetSprite(STONE);
            
        case PYRAMID:
            return o->SetSprite(PYRAMID);
            
        default:
            break;
    }
}

Drawable::Drawable()
{
}


Drawable::~Drawable()
{
}


int DrwCharacter::position[8][4] = {
    {10, 595, 86, 195},
    {194, 595, 78, 178},
    {115, 595, 60, 180},
    {175, 595, -60, 180},
    {100, 0, 100, 190},
    {100, 205, 100, 187},
    {100, 394, 100, 183},
    {100, 394, -100, 183}
};


DrwCharacter::DrwCharacter()
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/HumanRun.png");
    sprite.setTexture(texture);
    
    game = Game::Get();
    
      // initialize as static
}

sf::Sprite DrwCharacter::SetSprite()
{
    switch (game->character->dir) {
        case ST_BACK:
            sprite.setTextureRect(sf::IntRect(POSITION(ST_BACK)));
            break;
            
        case ST_FORWARD:
           sprite.setTextureRect(sf::IntRect(POSITION(ST_FORWARD)));
            break;
            
        case ST_LEFT:
            sprite.setTextureRect(sf::IntRect(POSITION(ST_LEFT)));
            break;
            
        case ST_RIGHT:
            sprite.setTextureRect(sf::IntRect(POSITION(ST_RIGHT)));
            break;
            
        case BACK:
            sprite.setTextureRect(sf::IntRect(POSITION_GO(BACK)));
            break;
            
        case FORWARD:
            sprite.setTextureRect(sf::IntRect(POSITION_GO(FORWARD)));
            break;
            
        case LEFT:
            sprite.setTextureRect(sf::IntRect(POSITION_GO(LEFT)));
            break;
            
        case RIGHT:
            sprite.setTextureRect(sf::IntRect(POSITION_GO(RIGHT)));
            break;
            
        default:
            break;
    }
    return sprite;
}


DrwCharacter::~DrwCharacter()
{
}


DrwObject::DrwObject()
{
    char adr[100];
    FILE * f = fopen("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Images.txt", "r");
    if(f == nullptr) printf("ERROR: Can't open Objects adr file\n");

    for(int i = 0; i < 5; i ++){
        fscanf(f, "%s", adr);
        textures[i].loadFromFile(adr);
        sprites[i].setTexture(textures[i]);
    }
    
    fclose(f);
}


sf::Sprite DrwObject::SetSprite(SPRITE_TYPE type)
{
    return sprites[type - 1];
}


DrwObject::~DrwObject()
{
    
}

