#ifndef SESSION_H
#define SESSION_H
#include "Map.h"
#include "../util/FileUtil.cpp"
class Session
{
private:
    Map map;
public:
    Session(/* args */) {

    }
    Session(std::string path) {
        map = Map(path);
    }
    Map* getMap(){
        return &map;
    }
    int finished();

    ~Session() {

    }
};

#endif