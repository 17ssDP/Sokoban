#include"Session.h"
#include<map>

int Session::finished(){
        // std::cout << "Session::finished()"<< std::endl;
        std::map<Position, Symbol>::iterator iter;
        for(iter = map.getElements().begin(); iter != map.getElements().end(); iter++) {
            if(iter->second == Trunk) {
                // std::cout << iter->first.getX() << iter->first.getY() << std::endl;
                return 0;
            }
        }
        return 1;
    }