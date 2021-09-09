#include <iostream>
using namespace std;
/*Provides an interface for creating families of related or dependant objects without specifying
their concrete class*/

class MazeFactory{
    public:
    virtual Maze* MakeMaze() const{return new Maze();}
    virtual Wall* MakeWall() const{return new Wall();}
    virtual Room* MakeRoom(int n) const{return new Room(n);}
    virtual Door* MakeDoor(Room* r1, Room* r2) const{return new Door(r1, r2);}
}

Maze* MazeGame::CreateMze(MazeFactory& fatory){
    Maze* aMaze = factory.MakeMaze();
}
