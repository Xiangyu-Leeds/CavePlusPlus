#ifndef COIN_H
#define COIN_H

#include "thing.h"

// a small coin that can be picked up.
class Coin : public Thing
{
    string getName()
    {
        //I need to return the name:coin
        return "coin";
    }
    Thing* clone(){
        //I need to clone coin
        return new Coin();
    }
};

#endif // COIN_H
