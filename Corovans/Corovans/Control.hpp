//
//  Control.hpp
//  Corovans
//
//  Created by Yaroslav on 10/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef Control_hpp
#define Control_hpp

#include <stdio.h>

#include "Game.hpp"
#include "View.hpp"

class Control: public Keypressable
{
public:
    Control(Character * c);
    ~Control();
    
    Character * character;
};


#endif /* Control_hpp */

