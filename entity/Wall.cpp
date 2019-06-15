#ifndef WALL
#define WALL
#include"Element.cpp"
class Wall : public Element
{
private:
    /* data */
public:
    Wall(Position pos) : Element(Mur, pos) {

    }
    ~Wall() {
        
    }
};

#endif