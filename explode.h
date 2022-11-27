#ifndef EXPLODE_H
#define EXPLODE_H

#include "command.h"
#include "mushroom.h"
#include "rock.h"
#include "bomb.h"
#include "location.h"
#include "coin.h"
#include <iostream>

using namespace std;
// check if explode
class Explode : public Command
{
public:
    Explode() : Command("explode") {}; // command:explode
    // start to fire
    void fire(Cave& c, string userCommand);

private:
    //this is the recursion
    void start(Cave& c, int x, int y);
};
#endif // EXPLODE_H
