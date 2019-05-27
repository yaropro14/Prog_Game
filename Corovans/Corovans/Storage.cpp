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
    so = new DrwObject();
    ca = new DrwCamel();
    s = new DrwSnake();
    ss = new SistemSprites;
    //drw[num++] = new DrwCharacter();
}


Storage::~Storage()
{
}

sf::Sprite Storage::GetSprite(SPRITE_TYPE type, Object * o)
{
    switch (type) {
        case CHARACTER:
            return c->SetSprite();
            break;
            
        case GREENERY:
            return so->SetSprite(GREENERY);
            
        case SCELET:
            return so->SetSprite(SCELET);
            
        case TREE:
            return so->SetSprite(TREE);
            
        case STONE:
            return so->SetSprite(STONE);
            
        case PYRAMID:
            return so->SetSprite(PYRAMID);
            
        case LIFE:
            return so->SetSprite(LIFE);
            
        case BRILLIANT:
            return so->SetSprite(BRILLIANT);
            
            
        case CAMEL:
            return ca->SetSprite();
            
        case SNAKE:
            return s->SetSprite(o);
            
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


DrwCamel::DrwCamel()
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Camel.png");
    sprite.setTexture(texture);
    
    game = Game::Get();
}


sf::Sprite DrwCamel::SetSprite()
{
    int step = game->corovan->step;
    switch (game->corovan->d) {
        case L:
            if(step % 7 == 0) step ++;
            sprite.setTextureRect(sf::IntRect(300 * (step % 7), 237 * (step / 7) + 5, -300, 239));
            break;
            
        case R:
            sprite.setTextureRect(sf::IntRect(300 * (step % 7), 237 * (step / 7) + 5, 300, 239));
            break;
            
        case N:
            sprite.setTextureRect(sf::IntRect(300 * (step % 7), 237 * (step / 7) + 5, 300, 239));
            break;
            
        default:
            break;
    }
    
    return sprite;
}


DrwCamel::~DrwCamel()
{
}


DrwObject::DrwObject()
{
    char adr[100];
    FILE * f = fopen("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Images.txt", "r");
    if(f == nullptr) printf("ERROR: Can't open Objects adr file\n");

    for(int i = 0; i < 7; i ++){
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


DrwSnake::DrwSnake()
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/SnakeBlue.png");
    sprite.setTexture(texture);
    
    game = Game::Get();
}

sf::Sprite DrwSnake::SetSprite(Object * o)
{
    switch (o->dir) {
        case BACK :
            sprite.setTextureRect(sf::IntRect(60 * o->step, 160, 60, 63));
            break;
            
        case FORWARD:
            sprite.setTextureRect(sf::IntRect(60 * o->step, 0, 60, 75));
            break;
            
        case LEFT:
            sprite.setTextureRect(sf::IntRect(63 * o->step + 2, 238, 63, 65));
            break;
            
        case RIGHT:
            sprite.setTextureRect(sf::IntRect(63 * o->step + 2, 83, 63, 72));
            break;
            
        case ST_BACK :
            sprite.setTextureRect(sf::IntRect(60 * o->step, 160, 60, 63));
            break;
            
        case ST_FORWARD:
            sprite.setTextureRect(sf::IntRect(60 * o->step, 0, 60, 75));
            break;
            
        case ST_LEFT:
            sprite.setTextureRect(sf::IntRect(63 * o->step, 238, 63, 65));
            break;
            
        case ST_RIGHT:
            sprite.setTextureRect(sf::IntRect(63 * o->step, 83, 63, 72));
            break;
            
        default:
            break;
    }
    
    return sprite;
}

DrwSnake::~DrwSnake()
{
}

SistemSprites::SistemSprites()
{
    t_life.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/heart.png");
    life.setTexture(t_life);
    t_b_life.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Bheart.png");
    b_life.setTexture(t_b_life);
    
    t_num.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Numbers.png");
    num.setTexture(t_num);
    
    t_wpoint.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Wpoint.png");
    wpoint.setTexture(t_wpoint);
    
    t_bril.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/SisBrilliant.png");
    bril.setTexture(t_bril);
    
    t_menu.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/menu.png");
    menu.setTexture(t_menu);
    
    t_menu2.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/menu2.png");
    menu2.setTexture(t_menu2);
    
    t_menu3.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/menu3.png");
    menu3.setTexture(t_menu3);
    
    t_menu4.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/menu4.png");
    menu4.setTexture(t_menu4);
}

SistemSprites::~SistemSprites()
{
}
