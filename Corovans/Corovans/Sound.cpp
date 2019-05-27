//
//  Sound.cpp
//  Corovans
//
//  Created by Yaroslav on 17/05/2019.
//  Copyright © 2019 Yaroslav. All rights reserved.
//

#include "Sound.hpp"


Sounds::Sounds()
{
    //game = Game::Get();

    if(!b_step.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/step.wav"))
        printf("probl\n");
    step.setBuffer(b_step);
    step.setVolume(10.f);
    
    if(!b_hit.loadFromFile("/Users/yaroslav/Desktop/Proga/Proj_Game/Corovans/Corovans/Resorses/gruntsound.wav"))
        printf("probl\n");
    hit.setBuffer(b_hit);
    hit.setVolume(60.f);
    
}


void Sounds::PlaySounds(SOUNDS s)
{
    switch (s) {
            
        case STEP:
            step.play();
            break;
            
        case HIT:
            hit.play();
            break;
            
        default:
            break;
    }
}

Sounds::~Sounds()
{
}
