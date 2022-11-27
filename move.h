#ifndef MOVE_H
#define MOVE_H

#include "cave.h"
#include "command.h"

#include <string>
#include <iostream>
#include <string>

using namespace std;


// a command to move tom around the cave.
class Move : public Command
{
public:
    Move() : Command("move") {};//command:move
    void fire(Cave& c, string userCommand); //trigger move
};

#endif // MOVE_H
