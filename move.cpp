#include "move.h"

void Move::fire(Cave& c, string userCommand)
{
    string s = tail(userCommand);

    int newTomX = c.getTom()->getX(),  newTomY = c.getTom()->getY();
    // check the direction
    if (s == "west")
        // point move west
        newTomX--;
    else if  (s == "north")
        // point move north
        newTomY--;
    else if  (s == "east")
        // point move east
        newTomX++;
    else if  (s == "south")
        // point move south
        newTomY++;
    else
    {
        // error input
        cerr << "tom can't \"" << s << "\"" << endl;
        return;
    }


    if (newTomX < 0 || newTomY < 0 || newTomX >= c.getWidth() ||newTomY >= c.getHeight())
    {
        // check the boundary
        cerr << "can't walk into the void" << endl;
        return;
    }
    else if ( c.getMap()[newTomX][newTomY] -> isBlocking() )
    {
        // check the blocking
        cerr << "something is blocking the way" << endl;
        return;
    }
    else if (newTomX != c.getTom()->getX() || newTomY != c.getTom()->getY())
    {
        //move successfully
        c.getTom() -> setLocation (&c, newTomX, newTomY);
        cerr << "tom shuffles through the dank cave" << endl;
        return;
    }
}
