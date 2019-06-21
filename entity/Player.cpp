#include"Player.h"
#include<map>
#include<assert.h>
Player::Player(Map eleMap) {
        std::map<Position, Symbol>::iterator iter;
        for(iter = eleMap.getElements().begin(); iter != eleMap.getElements().end(); iter++) {
            Symbol symbol = iter->second;
            if(symbol == Persion) {
                this->position = iter->first;
                break;
            }
        }
    }
int Player::validMove(Map eleMap, const Position pos) {
        Position temp(position.getX() + pos.getX(), position.getY() + pos.getY());
        Position temp2(position.getX() + 2 * pos.getX(), position.getY() + 2 * pos.getY());
        if(eleMap.getElements().find(temp)->second == Mur)
            return 0;
        if(eleMap.getElements().find(temp)->second == Trunk || eleMap.getElements().find(temp)->second == BoxOnTarget) {
            Symbol symbol = eleMap.getElements().find(temp2)->second;
            if(symbol == Trunk || symbol == Mur || symbol == BoxOnTarget)
                return 0;
        }
        return 1;
    } 

void Player::move(Map* eleMap, const Position pos) {
        if(eleMap->getElements().find(position)->second == Persion)
            eleMap->getElements()[position] = InOpen;
        else if(eleMap->getElements().find(position)->second == PersionOnTarget)
            eleMap->getElements()[position] = Target;
        this->position = Position(position.getX() + pos.getX(), position.getY() + pos.getY());
        Symbol symbol = eleMap->getElements().find(position)->second;
        // std::cout << symbol << std::endl;
        if(symbol == InOpen) {
            eleMap->getElements()[position] = Persion;
        }else if(symbol == Target) {
            eleMap->getElements()[position] = PersionOnTarget;
        }else if(symbol == Trunk) {
            Position temp = Position(position.getX() + pos.getX(), position.getY() + pos.getY());
            if(eleMap->getElements().find(temp)->second == Target) {
                eleMap->getElements()[position] = Persion;
                eleMap->getElements()[temp] = BoxOnTarget;
            }else if(eleMap->getElements().find(temp)->second == InOpen) {
                eleMap->getElements()[position] = Persion;
                eleMap->getElements()[temp] = Trunk;
            }
        }else if(symbol == BoxOnTarget) {
            Position temp = Position(position.getX() + pos.getX(), position.getY() + pos.getY());
            if(eleMap->getElements().find(temp)->second == Target) {
                eleMap->getElements()[position] = PersionOnTarget;
                eleMap->getElements()[temp] = BoxOnTarget;
            }else if(eleMap->getElements().find(temp)->second == InOpen) {
                eleMap->getElements()[position] = PersionOnTarget;
                eleMap->getElements()[temp] = Trunk;
            }  
        }
    }