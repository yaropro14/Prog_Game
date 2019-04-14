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
    char map[200][200];
    Map();
    ~Map();
    static Map * inst;
    static Map * Get();
    int map_size;
    
    sf::Texture background;
    sf::Sprite sand;
    sf::Sprite stone;
    
    /*
    sf::Texture double_palm_t;
    sf::Texture greenery_t;
    sf::Texture palm_t;
    sf::Texture small_sotne_t;
    sf::Texture banana_t;
    sf::Texture scelet_t;
    sf::Texture pyramid_t;
    sf::Texture coconut_t;
    
    sf::Sprite double_palm;
    sf::Sprite greenery;
    sf::Sprite palm;
    sf::Sprite small_sotne;
    sf::Sprite banana;
    sf::Sprite scelet;
    sf::Sprite pyramid;
    sf::Sprite coconut;
     */
};

#endif /* Map_Objects_hpp */
