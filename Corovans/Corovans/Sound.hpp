//
//  Sound.hpp
//  Corovans
//
//  Created by Yaroslav on 17/05/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

//#include "Game.hpp"

#ifndef Sound_hpp
#define Sound_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>

enum SOUNDS
{
    STEP,
    HIT,
    BRIL
};

class Sounds
{
public:
    Sounds();
    ~Sounds();
    
    void PlaySounds(SOUNDS s);
    
    //Game * game;
    
    sf::SoundBuffer b_step;
    sf::Sound step;
    
    sf::SoundBuffer b_hit;
    sf::Sound hit;
    
    sf::SoundBuffer b_bril;
    sf::Sound bril;
};

#endif /* Sound_hpp */
