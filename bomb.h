#ifndef BOMB_H
#define BOMB_H

#include "thing.h"

// a small glowing bomb on the ground, found wherever adventurers wander. Can be picked up.
class Bomb : public Thing
{

    string getName()
    {
        // return the name:bomb
        return "bomb";
    }
    Thing* clone(){
        // clone bomb
        return new Bomb();
    }
};

#endif // BOMB_H


