//
//  ControlHuman.cpp
//  Corovans
//
//  Created by Yaroslav on 10/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "ControlHuman.hpp"
#include "View.hpp"
#include <stdio.h>


ControlHuman::ControlHuman(Character * c):Control(c)
{
    View * v = View::Get();
    v->setonkey(this);
}


ControlHuman::~ControlHuman()
{
}


void ControlHuman::onkey()
{
    Game * g = Game::Get();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        character->SetDirection(RIGHT);
        //printf("event\n");
        //if (character->dir == RIGHT) printf("no event\n");
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        character->SetDirection(LEFT);
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        character->SetDirection(FORWARD);
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        character->SetDirection(BACK);
    }
    
    g->Move();
    
    
    View * v = View::Get();
    v->Draw();
}
