#include "place.h"
#include "thing.h"

void Place::fire(Cave& c, string userCommand)
{
    string s = tail(userCommand);
    Location* loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()];

    if (s.compare("coin")==0)
        //if s==coin I need to add a coin
        loc ->add(new Coin());
    else if (s.compare("mushroom")==0)
        //if s==coin I need to add a mushroom
        loc ->add(new Mushroom());
    else if (s.compare("bomb")==0)
        //if s==bomb I need to add a bomb
        loc ->add(new Bomb());
    else
        //other error input
        cerr << "I don't know how to place a " << userCommand << endl;
}
