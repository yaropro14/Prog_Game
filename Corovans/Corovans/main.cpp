//
//  main.cpp
//  Proj_Game
//
//  Created by Yaroslav on 31/03/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include <stdio.h>

#include "View.hpp"


int main()
{
    View * v = View::Get();
    
    //v->Draw();
    v->Run();
    return 0;
}
