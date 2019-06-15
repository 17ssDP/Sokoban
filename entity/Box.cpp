#ifndef BOX
#define BOX
#include"Symbol.cpp"
#include"Position.cpp"
#include"Map.cpp"
class Box : public Element
{
private:
    bool isOn;
public:
    Box(Position pos) : Element(Trunk, pos), isOn(false){

    }
    // int validMove(Position pos,Map eleMap) {
    //     return ((eleMap.getElements().find(position)->second != Mur)
    //             && (eleMap.getElements().find(position)->second != Trunk));
    // }
    void move(Position pos) {
        this->position.setX(position.getX() + pos.getX());
        this->position.setY(position.getY() + pos.getY());       
    }
    ~Box() {

    }
};
#endif