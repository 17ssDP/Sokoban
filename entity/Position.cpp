#ifndef POSITION
#define POSITION
#include <map>
class Position
{
private:
    int x;
    int y;
public:
    Position() {
        
    }
    Position(int x, int y) : x(x), y(y) {

    };
    bool operator<(const Position& other) const {
        return (100 * x + y) < (100 * other.x + other.y);
    }
    int getX() const {
        return x;
    } 
    int getY() const {
        return y;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int Y) {
        this->y = y;
    }
    ~Position() {

    }
};

#endif //Position