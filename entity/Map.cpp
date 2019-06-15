#ifndef MAP
#define MAP
#include"../util/FileUtil.cpp"
#include"Position.cpp"
#include"Symbol.cpp"
#include"Element.cpp"
#include"Wall.cpp"
#include"Player.cpp"
#include"Box.cpp"
#include"Object.cpp"
#include<assert.h>
class Map
{
private:
    int row;
    int col;
    std::map<Position, Element> elements;
    Element* intToElement(int x, int y, int num) {
        assert(num >= 0 && num <= 9);
        switch (num)
        {
            case 0: case 2:
                return new Element(OutOpen, Position(x, y));
            case 1:
                return new Wall(Position(x, y));
            case 3:
                return new Box(Position(x, y));
            case 4:
                return new Object(Position(x, y));
            case 5: case 6: case 7: case 8:
                return new Player(Position(x, y));
            default:
                return new Element(OutOpen, Position(x, y));
        }
    }
public:
    Map() {
        
    }
    Map(const std::string path) {
        int **intMap = FileUtil::getMap(path);
        int *size = FileUtil::getSize(path);
        row = size[0];
        col = size[1];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                elements.insert(std::pair<Position, Element>(Position(i, j), *intToElement(i, j, intMap[i][j])));
            }
        }
    }

    const std::map<Position, Element> getElements() const {
        return elements;
    }
    int getRow() {
        return row;
    }
    int getCol() {
        return col;
    }
    // void print() {
    //     // std::cout << elements.size() << std::endl;
    //     std::map<Position, Element>::iterator iter;
    //     for(iter = elements.begin(); iter != elements.end(); iter++) {
    //         Element symbol = iter->second;
    //         switch (symbol)
    //         {
    //         case Mur:
    //             std::cout << "wall" << std::endl;
    //             break;
    //         default:
    //             std::cout << "NotWall" << std::endl;
    //         }
    //     }
    // }
    ~Map();
};

Map::~Map()
{
}

#endif //MAP