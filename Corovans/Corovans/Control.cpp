//
//  Control.cpp
//  Corovans
//
//  Created by Yaroslav on 10/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Control.hpp"


Control::Control(Character * c)
{
    View * v = View::Get();
    v->setonkey(this);
    character = c;
}

Control::~Control()
{
}

