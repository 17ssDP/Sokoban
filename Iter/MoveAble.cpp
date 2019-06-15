#ifndef MOVEABLE
#define MOVEABLE
#include"../entity/Map.cpp"
#include"../entity/Position.cpp"
class MoveAble
{
public:
    MoveAble(/* args */);
    virtual int validMove(Map eleMap, Position pos) {

    }
    virtual void move(Position pos) {

    }
    ~MoveAble();
};

MoveAble::MoveAble(/* args */)
{
}

MoveAble::~MoveAble()
{
}

#endif // MOVEABLE