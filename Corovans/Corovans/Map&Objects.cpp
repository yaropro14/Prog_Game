//
//  Map&Objects.cpp
//  Corovans
//
//  Created by Yaroslav on 31/03/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Map&Objects.hpp"

Map * Map::inst;

Map::Map()
{
    x_size = 100;
    y_size = 100;
    for(auto row : map) {
        for(int i = 0; i < 100; i++){
            row[i] = 's';
        }
    }
}

Map * Map::Get()
{
    if(inst != nullptr)    return inst;
    
    inst = new Map;
    return inst;
}

Map::~Map()
{
    
}
