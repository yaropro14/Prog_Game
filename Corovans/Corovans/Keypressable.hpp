//
//  Keypressable.hpp
//  Corovans
//
//  Created by Yaroslav on 10/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef Keypressable_hpp
#define Keypressable_hpp

#include <stdio.h>

class Keypressable
{
public:
    virtual void onkey() = 0;
};

#endif /* Keypressable_hpp */
