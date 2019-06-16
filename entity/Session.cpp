#ifndef SESSION
#define SESSION
#include "Map.cpp"
#include "../util/FileUtil.cpp"
#include<map>
class Session
{
private:
    Map map;
public:
    Session() {
        
    }
    Session(std::string path) {
        map = Map(path);
    }
    int finished(){
        std::map<Position, Symbol>::iterator iter;
        for(iter = map.getElements().begin(); iter != map.getElements().end(); iter++) {
            if(iter->second == Trunk) {
                std::cout << iter->first.getX() << iter->first.getY() << std::endl;
                return 0;
            }
        }
        return 1;
    }
    Map* getMap(){
        return &map;
    }
    ~Session();
};

Session::~Session()
{
}

#endif //SESSION