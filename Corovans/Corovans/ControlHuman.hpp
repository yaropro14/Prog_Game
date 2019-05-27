//
//  ControlHuman.hpp
//  Corovans
//
//  Created by Yaroslav on 10/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef ControlHuman_hpp
#define ControlHuman_hpp

#include <stdio.h>
#include "Game.hpp"
#include "Control.hpp"
#include "Keypressable.hpp"


class ControlHuman : public Control
{
public:
    ControlHuman(Character * c);
    ~ControlHuman();
    bool onkey();
};

#endif /* ControlHuman_hpp */
