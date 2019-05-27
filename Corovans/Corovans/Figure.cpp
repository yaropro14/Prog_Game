//
//  Figure.cpp
//  Corovans
//
//  Created by Yaroslav on 23/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Figure.hpp"


Figure::Figure()
{
}

Figure::~Figure()
{
}


int Mod(int a)
{
    if(a > 0)   return a;
    else return -a;
}


int Coord::Distance(const Coord &c) const
{
    return Mod(c.first - first) + Mod(c.second - second);
}
