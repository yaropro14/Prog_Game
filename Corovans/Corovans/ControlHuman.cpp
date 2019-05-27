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


bool ControlHuman::onkey()
{
    Game * g = Game::Get();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))    character->speed = 20;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H) && !character->hit){
        character->step = 1;
        //character->speed = 0;
        character->hit = true;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !character->rob){
        character->rob = true;
        character->step = 1;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        return character->SetDirection(RIGHT);
//        g->character->Move();
        //g->Move();
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        return character->SetDirection(LEFT);
//        g->character->Move();
//        g->Move();
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        return character->SetDirection(FORWARD);
//        g->character->Move();
//        g->Move();
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        return character->SetDirection(BACK);
//        g->character->Move();
//        g->Move();
    }
    
    
    View * v = View::Get();
//    v->Draw();
    return false;
}
