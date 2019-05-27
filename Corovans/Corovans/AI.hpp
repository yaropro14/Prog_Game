//
//  AI.hpp
//  Corovans
//
//  Created by Yaroslav on 06/05/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

#include <stdio.h>


#include "Control.hpp"

class Game;


class SnakeAI
{
public:
    SnakeAI(Snake * s);
    SnakeAI();
    
    void OnMove();
    
    Snake * snake;
};


#endif /* AI_hpp */
