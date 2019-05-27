//
//  Figure.hpp
//  Corovans
//
//  Created by Yaroslav on 23/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef Figure_hpp
#define Figure_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include <cstdlib>


struct Coord : public std::pair<int, int>
{
    using Base = std::pair<int, int>;
    int Distance(const Coord & c) const;
    using Base::Base;
};


class Figure
{
public:
    Figure();
    ~Figure();
    Coord position;
    int x;
    int y;
};


#endif /* Figure_hpp */
