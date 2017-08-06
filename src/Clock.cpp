//
//  Clock.cpp
//  Bobo
//
//  Created by Jas S on 2017-02-04.
//  Copyright © 2017 Jas S. All rights reserved.
//

#include "Clock.h"

Clock GlobalClock = Clock(1000);

Clock::Clock(Uint32 milliseconds)
{
    this->ms = milliseconds;
    this->last = SDL_GetTicks();
}
