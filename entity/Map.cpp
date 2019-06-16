#ifndef MAP
#define MAP
#include"../util/FileUtil.cpp"
#include"Position.cpp"
#include"Symbol.cpp"
#include<assert.h>
class Map
{
private:
    int row;
    int col;
    std::map<Position, Symbol> elements;
    Symbol intToElement(int num) {
        assert(num >= 0 && num <= 9);
        switch (num)
        {
            case 0: 
                return OutOpen;
            case 1:
                return Mur;
            case 2:
                return InOpen;
            case 3:
                return Trunk;
            case 4:
                return Target;
            case 5: case 6: case 7: case 8:
                return Persion;
            case 9:
                return BoxOnTarget;
            default:
                return InOpen;
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
                elements.insert(std::pair<Position, Symbol>(Position(i, j), intToElement(intMap[i][j])));
            }
        }
    }

    Map(std::map<Position, Symbol> ele) {
        elements = ele;
    }

    std::map<Position, Symbol>& getElements(){
        return elements;
    }
    int getRow() {
        return row;
    }
    int getCol() {
        return col;
    }
    void print() {
        // std::cout << elements.size() << std::endl;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                std::cout << getSympol(elements.find(Position(i, j))->second);
            }
            std::cout << std::endl;
        }
    }
    static char getSympol(Symbol ele) {
        switch (ele)
        {
        case OutOpen:
            return ' ';
        case Mur:
            return 'W';
        case InOpen:
            return ' ';
        case Trunk:
            return 'B';
        case Target:
            return 'O';
        case Persion:
            return 'P';
        case BoxOnTarget:
            return 'B';
        case PersionOnTarget:
            return 'P';
        default:
            return ' ';
        }
    }
    ~Map();
};

Map::~Map()
{
}

#endif //MAP