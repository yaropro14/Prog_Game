//
//  main.cpp
//  Proj_Game
//
//  Created by Yaroslav on 31/03/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//


#include <time.h>


#include <stdio.h>

#include "View.hpp"
#include "Game.hpp"
#include "Control.hpp"
#include "ControlHuman.hpp"
#include "AI.hpp"
#include "Sound.hpp"


int main()
{
    srand(time(NULL));
    
    View * v = View::Get();
    Game * g = Game::Get();
    
    Character * c = new Character;
    
    g->character = (Character *) c;
    
    Sounds * s = new Sounds();
    
    g->SetSound(s);
    
    Corovan * corovan = new Corovan();
    g->corovan = corovan;
    
    g->CreateField();
    
    g->NewLife();
    
    v->set_model(g);
    
    ControlHuman h((Character *)c);
    
    g->Move();
    v->Run();
    return 0;
}
