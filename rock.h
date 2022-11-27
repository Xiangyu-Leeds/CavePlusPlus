#ifndef ROCK_H
#define ROCK_H

#include "blocks.h"
#include "thing.h"
#include <string>

// a giant bolder that stops tom from walking through this location
class Rock: public Thing, public Blocks
{
public:
    Rock(){};
    ~Rock(){};
    string getName()
    {
        // return the name:rock
        return "rock";
    }
    Thing* clone(){
        //clone rock
        return new Rock();
    }
};

#endif // ROCK_H
