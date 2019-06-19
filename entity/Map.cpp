#include"Map.h"
Symbol Map:: intToElement(int num) {
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

std::string Map::ElementToSympol(Symbol ele) {
        switch (ele)
        {
        case OutOpen:
            return "¡¡";
        case Mur:
            return "¨ˆ";
        case InOpen:
            return "¡¡";
        case Trunk:
            return "¡õ";
        case Target:
            return "¡ð";
        case Persion:
            return "¡â";
        case BoxOnTarget:
            return "¡ö";
        case PersionOnTarget:
            return "¡â";
        default:
            return "¡¡";
        }
}
Map::Map(const std::string path) {
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

Map::Map(std::map<Position, Symbol> ele) {
        elements = ele;
    }

void Map::print() {
        // std::cout << elements.size() << std::endl;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                std::cout << ElementToSympol(elements.find(Position(i, j))->second);
            }
            std::cout << std::endl;
        }
    }
