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
    map_size = 200;
    for(auto row : map) {
        for(int i = 0; i < 200; i++){
            if(i == 0 || i == 199 || row == map[0] || row == map[99])
                row[i] = 's';
            else
                row[i] = '0';
        }
    }
    background.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Bacground.png");
    sand.setTexture(background);
    sand.setTextureRect(sf::IntRect(0, 0, 70, 70));
    
    stone.setTexture(background);
    stone.setTextureRect(sf::IntRect(70, 0, 70, 70));
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

/*
 double_palm_t.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Tree.png");
 greenery_t.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Greenery.png");
 palm_t.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Palm.png");
 small_sotne_t.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/S_stone.png");
 banana_t.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Banana.png");
 scelet_t.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Scelet.png");
 pyramid_t.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Pyramid.png");
 coconut_t.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Coconut.png");
 
 double_palm.setTexture(double_palm_t);
 greenery.setTexture(greenery_t);
 palm.setTexture(palm_t);
 small_sotne.setTexture(small_sotne_t);
 banana.setTexture(banana_t);
 scelet.setTexture(scelet_t);
 pyramid.setTexture(pyramid_t);
 coconut.setTexture(coconut_t);
 */
