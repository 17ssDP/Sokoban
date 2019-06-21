#ifndef FILE_UTIL
#define FILE_UTIL
#include<cstring>
#include<fstream>
#include<iostream>
class FileUtil
{
public:
    static int** getMap(const std::string path) {
        std::ifstream in(path);
        std::string input;
        in >> input;
        int col = atoi(input.c_str());
        in >> input;
        int row = atoi(input.c_str());
        int **map = new int*[row];
        for(int i = 0; i < row; i++) {
            map[i] = new int[col];
        }
        row = 0;
        while(in >> input) {
            for(int i = 0; i < col; i++) {
                map[row][i] = atoi(input.substr(i, 1).c_str());
            }
            row++;
        }
        return map;
    }
    static int* getSize(std::string path) {
        std::ifstream in(path);
        std::string input;
        in >> input;
        int col = atoi(input.c_str());
        in >> input;
        int row = atoi(input.c_str());
        int *len;
        len = (int *)malloc(2 * sizeof(int));
        len[0] = row;
        len[1] = col;
        return len;
    }
};

#endif //FILT_UTIL