//
//  ActiveObjects.cpp
//  Corovans
//
//  Created by Yaroslav on 11/04/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "ActiveObjects.hpp"


ActiveObjects::ActiveObjects()
{
}

ActiveObjects::~ActiveObjects()
{
}


Palm::Palm(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Palm.png");
    sprite.setTexture(texture);
}


Palm::~Palm()
{
    
}


Palm2::Palm2(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Tree.png");
    sprite.setTexture(texture);
}


Palm2::~Palm2()
{
    
}


Banana::Banana(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Banana.png");
    sprite.setTexture(texture);
}


Banana::~Banana()
{
    
}


Coconut::Coconut(Coord c)
{
    texture.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/Tree.png");
    sprite.setTexture(texture);
}


Coconut::~Coconut()
{
    
}
