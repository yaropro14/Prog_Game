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
    v->SetOnKey(this);
}


ControlHuman::~ControlHuman()
{
}


void ControlHuman::onkey()
{
    Game * g = Game::Get();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))    character->speed = 20;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        character->SetDirection(RIGHT);
        g->Move();
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        character->SetDirection(LEFT);
        g->Move();
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        character->SetDirection(FORWARD);
        g->Move();
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        character->SetDirection(BACK);
        g->Move();
    }
    
    View * v = View::Get();
    v->Draw();
}
