//
//  AI.cpp
//  Corovans
//
//  Created by Yaroslav on 06/05/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//


#include <iostream>
#include <random>
#include <cstdlib>
#include <algorithm>
#include <list>


#include "AI.hpp"
#include "View.hpp"


SnakeAI::SnakeAI(Snake * s)
{
    snake = s;
    Game::Get()->SetOnSnakeAI(this);
}


void SnakeAI::OnMove()
{
    Coord next_p = snake->NextPosition();
    if(snake->CheckPosition(next_p) == CHARACTER)
    {
        snake->bite = true;
        switch (snake->dir) {
            case BACK:
                snake->dir = ST_BACK;
                break;
                
            case FORWARD:
                snake->dir = ST_FORWARD;
                break;
                
            case LEFT:
                snake->dir = ST_LEFT;
                break;
                
            case RIGHT:
                snake->dir = ST_RIGHT;
                break;
                
            default:
                break;
        }
        return;
    }
    
    Dir d[4] = {FORWARD, BACK, LEFT, RIGHT};
    Dir st_dir = snake->dir;
    std::random_device rd;
    std::mt19937 g(rd());
    
//    if(snake->step == 0 || snake->step == 3)
        std::shuffle(d, d + 4, g);
    
    Game * game = Game::Get();
    Coord r = game->character->position;
    
    snake->dir = NO;
    
    bool ok = false;
    
    int now = r.Distance(snake->position);
    
    for(auto p : d)
    {
        snake->dir = p;
        Coord next_p = snake->NextPosition();
        int next = r.Distance(next_p);
        if(next < now && snake->CheckPosition(next_p) == SNAKE)
        {
            ok = true;
            break;
        }
    }
    
    if(now > 800)
    {
        snake->dir = st_dir;
        Coord next_p = snake->NextPosition();
        int next = r.Distance(next_p);
        if(snake->CheckPosition(next_p) == SNAKE)
        {
            ok = true;
        }
        else ok = false;
    }
    
    if(!ok)
        for(auto p : d)
        {
            snake->dir = p;
            Coord c = snake->NextPosition();
            if(snake->CheckPosition(c) == SNAKE)
            {
                break;
            }
        }
    
}


SnakeAI::SnakeAI()
{
}
