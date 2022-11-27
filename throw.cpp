#include "throw.h"
#include "thing.h"
using namespace std;

void Throw::fire(Cave& c, string userCommand)
{
    string s = tail(userCommand);
    int newTomX = c.getTom()->getX(),  newTomY = c.getTom()->getY();
    // check the direction and object
    if (s == "coin west" || s == "mushroom west") {
        // if throw west of coin or mushroom, move west
        newTomX--;
    }
    else if  (s == "coin north" || s == "mushroom north") {
        // if throw north of coin or mushroom, move north
            newTomY--;
        }
    else if  (s == "coin east" || s == "mushroom east") {
        // if throw east of coin or mushroom, move east
        newTomX++;
    }
    else if  (s == "coin south" || s == "mushroom south") {
        // if throw south of coin or mushroom, move south
        newTomY++;
    }
    else
        {
        //other error information
            cerr << "tom can't \"" << s << "\"" << endl;
            return;
        }
    if (newTomX < 0 || newTomY < 0 || newTomX >= c.getWidth() ||newTomY >= c.getHeight())
    {
        //I need to check the boundary
        cerr << "can't walk into the void" << endl;
        return;
    }
    else if ( c.getMap()[newTomX][newTomY] -> isBlocking() )
    {
        //I need to check the blocking
        cerr << "something is blocking the way" << endl;
        return;
    }

    Location* loc = c.getMap()[newTomX][newTomY];
    //I need to check whether s[0,4]==coin
    if (s.substr(0, 4).compare("coin")==0)
        loc ->add(new Coin());
    else if (s.substr(0, 8).compare("mushroom")==0)
        //I need to check whether s[0,8]==mushroom
        loc ->add(new Mushroom());
    else
        //an error
        cerr << "I don't know how to place a " << userCommand << endl;
}
