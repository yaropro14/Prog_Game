//
//  main.cpp
//  Proj_Game
//
//  Created by Yaroslav on 31/03/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include <stdio.h>

#include "View.hpp"
#include "Game.hpp"
#include "Control.hpp"
#include "ControlHuman.hpp"


int main()
{
    View * v = View::Get();
    Game * g = Game::Get();
    
    Character * c = new Character;
    
    g->character = c;
    
    v->set_model(g);
    
    ControlHuman h(c);
    
    Object * pyr = new Pyramid(Coord(400, 800));
    Object * gre = new Greenery(Coord(2000, 600));
    Object * sto = new Stone(Coord(600,1600));
    Object * tre = new Tree(Coord(3000, 1400));
    Object * sce = new Scelet(Coord(1500, 1300));
    
    g->AddObject(pyr);
    g->AddObject(gre);
    g->AddObject(sto);
    g->AddObject(sce);
    g->AddObject(tre);
    
    //v->Draw();
    v->Run();
    return 0;
}
