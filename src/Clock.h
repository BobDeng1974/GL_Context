//
//  Clock.hpp
//  Bobo
//
//  Created by Jas S on 2017-02-04.
//  Copyright © 2017 Jas S. All rights reserved.
//

#ifndef Clock_hpp
#define Clock_hpp

#include <stdio.h>
#include <time.h>
#include <SDL2/SDL.h>

class Clock
{
private:
    Uint32 current;
    Uint32 last;
    Uint32 ms;
public:
    Clock(){}
    Clock(Uint32 milliseconds);
    
    inline bool tick()
    {
        current = SDL_GetTicks();
        if(this->current - this->last >= this->ms)
        {
            this->last = this->current;
            return true;
        }
        return false;
    }
    
    inline float getDelta() const {
        return (this->current - this->last) / (double) this->ms;
    }
};

extern Clock GlobalClock;

#endif /* Clock_hpp */
