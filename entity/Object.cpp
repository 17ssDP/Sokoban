#ifndef OBJECT
#define ONJECT
#include "Element.cpp"
class Object : public Element
{
private:
    int isUnder;
public:
    Object(Position pos) : Element(Target, pos) {

    } 
    ~Object() {
        
    }
};

#endif