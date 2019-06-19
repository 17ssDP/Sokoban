#ifndef PLAYER_H
#define PLAYER_H
#include"Position.h"
#include"Map.h"
#include"Symbol.h"
#include<map>
class Player
{
private:
    const Symbol symbol = Persion;
    Position position;
public:
    Player() {

    }
    Player(Position pos);
    Player(Map eleMap);
    int validMove(Map eleMap, const Position pos);
    void move(Map* eleMap, const Position pos);
    ~Player() {
        
    }
};

#endif