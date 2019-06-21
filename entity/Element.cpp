#ifndef ELEMENT
#define ELEMENT
#include"Symbol.h"
#include"Position.h"
class Element
{
protected:
    const Symbol symbol;
    Position position;
public:
    Element(): symbol(OutOpen) {

    }
    
    Element(Symbol sym, Position pos) : symbol(sym), position(pos) {

    }

    Symbol getSymbol() const {
        return symbol;
    }
    Position getPosition( ) const {
        return position;
    }
    ~Element() {

    }
};

#endif