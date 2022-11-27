#include "thing.h"
#include "explode.h"

//used to move east,south,west and north
const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,1,-1,0};

void Explode::fire(Cave& c, string userCommand)
{
    // get x of Tom
    int newTomX = c.getTom()->getX();
    // get y of Tom
    int newTomY = c.getTom()->getY();
    //used to check the position of Tom
    int status = 0;
    // get the map
    Location*** map = c.getMap();
    auto thingsWithTom1 = map[newTomX][newTomY]->getThings();
    //get the size of this point
    int a = (int)thingsWithTom1 -> size();
    for (int i = 0; i < a; ++i) {
        // check the bomb
        if((*thingsWithTom1)[i]->getName() == "bomb"){
            for (int j = 0; j < a; ++j) {
                // check the tom
                if((*thingsWithTom1)[status]->getName() != "tom"){
                    //not tom and delete the element
                    map[newTomX][newTomY]->remove((*thingsWithTom1)[status]);
                }else{
                    //if it is tom, change the number of status
                    status=1;
                }
            }
        }
    }
    // start to recursion
    for (int i = 0; i < 4; i++) {
        // used to move east,south,west and north
        int mx = newTomX+ dx[i], my = newTomY + dy[i];
        start(c,mx,my);
    }
}

void Explode::start(Cave& c, int new_x, int new_y){
    // check the position and if it crosses the boundary, exit
    if(new_x<0||new_x>=c.getWidth()||new_y<0||new_y>=c.getHeight()){
        return;
    }
    // check if it has bomb
    bool f = false;
    for(int i = 0; i < c.getMap()[new_x][new_y]->getThings()->size();i++)
    if((*c.getMap()[new_x][new_y]->getThings())[i]->getName() == "bomb")
    {
        // it has bomb
        f = true;
    }
    if(!f)
        // it doesn't have bomb and exit
        return ;
    int status = 0;
    Location*** map = c.getMap();
    // get the contents of this point
    auto thingsWithTom1 = map[new_x][new_y]->getThings();
    int a = (int)thingsWithTom1 -> size();
            for (int j = 0; j < a; ++j) {
                // check the tom
                if((*thingsWithTom1)[status]->getName() != "tom"){
                    //not tom and delete the element
                    map[new_x][new_y]->remove((*thingsWithTom1)[status]);
                }else{
                    //if it is tom, change the number of status
                    status=1;
                }
            }
     // the change of the position
    for (int i = 0; i < 4; i++) {
        // used to move east,south,west and north
        int mx = new_x + dx[i], my = new_y + dy[i];
        //start to recursion
        start(c,mx,my);
    }

}
