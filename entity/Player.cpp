#ifndef PLAYER
#define PLAYER
#include"Position.cpp"
// #include"Map.cpp"
#include"Symbol.cpp"
#include<map>
class Player : public Element
{
private:
    // const Symbol symbol = Persion;
    // Position position;
public:
    Player(Position pos) : Element(Persion, pos) {

    }

    // int validMove(const Map eleMap, const Position pos) {
    //     Position temp(position.getX() + pos.getX(), position.getY() + pos.getY());
    //     Position temp2(position.getX() + 2 * pos.getX(), position.getY() + 2 * pos.getY());
    //     if(eleMap.getElements().find(temp)->second == Mur)
    //         return 0;
    //     if((eleMap.getElements().find(temp)->second == Trunk) && (eleMap.getElements().find(temp2)->second == Trunk))
    //         return 0;
    // } 

    void move(Position pos) {
        this->position.setX(position.getX() + pos.getX());
        this->position.setY(position.getY() + pos.getY());
    }

    ~Player() {
        
    }
};

#endif