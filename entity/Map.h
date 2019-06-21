#ifndef MAP_H
#define MAP_H
#include"../util/FileUtil.cpp"
#include"Position.h"
#include"Symbol.h"
#include<assert.h>
class Map
{
private:
    int row;
    int col;
    std::map<Position, Symbol> elements;
    Symbol intToElement(int num);
    std::string ElementToSympol(Symbol ele);
public:
    Map() {
        
    }
    Map(const std::string path);
    Map(std::map<Position, Symbol> ele);
    void print();
    std::map<Position, Symbol>& getElements(){
        return elements;
    }
    int getRow() {
        return row;
    }
    int getCol() {
        return col;
    }
    ~Map(){

    }
};

#endif