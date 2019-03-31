//
//  Map&Objects.hpp
//  Corovans
//
//  Created by Yaroslav on 31/03/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#ifndef Map_Objects_hpp
#define Map_Objects_hpp

#include <stdio.h>
#include <string>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Map
{
public:
    std::string map[100][100];
    Map();
    ~Map();
    static Map * inst;
    static Map * Get();
    int x_size, y_size;
    sf::Sprite sand;
};

#endif /* Map_Objects_hpp */
