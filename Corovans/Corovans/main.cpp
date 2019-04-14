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
    
    Object * pyr = new Pyramid(Coord(1000, 600));
    Object * gre = new Greenery(Coord(2300, 1110));
    Object * sto = new Stone(Coord(1400,1200));
    //Object * tre = new Tree(Coord(500, 300));
    Object * sce = new Scelet(Coord(3000, 700));
    
    g->AddObject(pyr);
    g->AddObject(gre);
    g->AddObject(sto);
    g->AddObject(sce);
    
    //v->Draw();
    v->Run();
    return 0;
}
