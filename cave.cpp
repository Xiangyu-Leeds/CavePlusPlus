#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <string>

#include "cave.h"
#include "rock.h"
#include "thing.h"
#include "location.h"
#include "move.h"
#include "place.h"
#include "throw.h"
#include "explode.h"


using namespace std;

Cave::Cave(int w, int h) : width(w), height(h) // width and height of the cave
{
//    if (width != 8 || height != 8) // be sure to update Cave::show() if you remove this.
//        throw new logic_error("fixme: Cave needs to be fixed for non-standard sizes.");

    // I need to control the size of the cave to avoid a too small map
    if ( width < 5 || height < 5)
        throw new logic_error("cavex too small for tom.");

    // I need to create a map to store things
    map = new Location**[width];

    for (int x = 0; x < width; x++)
    {
        // I need to get a new location to column
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++){
            column[y] = new Location();
        }

    }

    // create some rocks
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            if ( x == 0 || y == 0 || x == width-1 || y == height-1 )
                 map[x][y] -> add( new Rock() );

    tom = new Tom();
    // add tom to the middle of the map
    tom -> setLocation( this, width/2,height/2);
}

//  a copy constructor of cave
Cave::Cave(const Cave& m)
{
    //I need to copy the width
    width = m.width;
    //I need to copy the height
    height = m.height;
    //I need to copy the map
    map = new Location**[width];
    //I need to assign the map
    for (int x = 0; x < width; x++)
    //from 0 to width
    {
        Location** column = new Location*[height];
        map[x] = column;
        // from 0 to height
        for (int y = 0; y < height; y++)
            column[y] = new Location(*m.map[x][y]);
    }
    //I need to copy the tom
    tom = new Tom();
    // I deliver three augments to setLocation function, using this function can set the position of tom in the map
    tom->setLocation(this,m.tom->getX(),m.tom->getY());


}

// The Cave destructor
Cave::~Cave()
{
    //I need to delete the map
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            //I need to delete the inner part
            delete(map[i][j]);
        }
        //I need to delete the outer part
        delete(map[i]);
    }
    // fixme: I don't think this deletes all Locations and arrays declared in the constructor...
    //I need to delete the whole part
    delete[] map; // fixme: ...neither does this.

}

void Cave::command (string userCommand)
{
    // trigger Move() to let it move
    if (Move().triggersOn(userCommand))
        Move().fire(*this, userCommand);
    // trigger Place() to let it place
    else if (Place().triggersOn(userCommand))
        Place().fire(*this, userCommand);
    // trigger Throw() to let it throw
    else if (Throw().triggersOn(userCommand))
        Throw().fire(*this, userCommand);
    // trigger Explode() to let it explode
    else if (Explode().triggersOn(userCommand))
        Explode().fire(*this, userCommand);
    else
        // trigger nothing if some error input
        cerr << "tom doesn't know how to "+userCommand << endl;;
}

void Cave::show()
{
    vector<Thing*>* thingsWithTom = map[tom -> getX()][tom -> getY()] -> getThings();

    for (int y = 0; y < height; y++)
    { // for all rows
        for (int x = 0; x < width; x++) // for all columns
            cout << map[x][y] -> show(); // output whatever we find there

        cout << "  "; // list the things at this location
        if (y <  (int) thingsWithTom -> size())
            cout << (*thingsWithTom)[y] -> getName();

        cout << endl;
    }

    cout << endl;
}
// a copy assignment operator
Cave& Cave::operator=(const Cave& c)
{
    // copy the width
    width = c.width;
    // copy the height
    height = c.height;
    //I need to copy the map
    map = new Location**[width];
    for (int x = 0; x < width; x++)
    {
        //I need to copy a new location to column
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++)
            column[y] = new Location(*c.map[x][y]);
    }
    // I need to copy the tom
    tom = new Tom();
    // I deliver three augments to setLocation function, using this function can set the position of tom in the map
    tom->setLocation(this,c.tom->getX(),c.tom->getY());
    return *this;
}
