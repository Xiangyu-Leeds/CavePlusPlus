#ifndef THROW_H
#define THROW_H

#include "coin.h"
#include "command.h"
#include "mushroom.h"
#include "rock.h"
#include <iostream>

using namespace std;

class Throw : public Command
{
public:
    Throw() : Command("throw") {}; //the command:throw
    void fire(Cave& c, string userCommand); //I need to trigger throw
};
#endif // THROW_H
