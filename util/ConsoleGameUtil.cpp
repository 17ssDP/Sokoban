#ifndef CONSOLEGAME_UTIL
#define CONSOLEGAME_UTIL
#include"../entity/Symbol.cpp"
#include"../entity/Map.cpp"
#include<map>
#include<iostream>
#include<string>
class ConsoleGameUtil
{
public:
    static char getSympol(Element ele) {
        switch (ele.getSymbol())
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
        default:
            return ' ';
        }
    }

    static void display(Map eleMap) {
        for(int i = 0; i < eleMap.getRow(); i++) {
            for(int j = 0; j < eleMap.getCol(); j++) {
                std::cout << getSympol(eleMap.getElements().find(Position(i, j))->second);
            }
            std::cout << std::endl;
        }
    }

    static void resolveInput() {
        std::string input;
        getline(std::cin, input);
        if(input.length() != 1) {
            resolveInvalidInput();
            return;
        }
        char order = input.at(0);
        switch (order)
        {
        case 'W':case 'A': case 'S': case 'D': 
            resolveMove(order);
            break;
        case 'Q':
            exit(0);
        case 'H':
            resolveHelp();
            break;
        case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            resolveBarrierChoose(order);
            break;
        default:
            resolveInvalidInput();
            break;
        }
    }

    static void resolveMove(const char move) {
        switch (move)
        {
        case 'w':
            
            break;
        
        default:
            break;
        }
    }

    static void resolveHelp() {
        std::cout << "Help" << std::endl;
    }

    static void resolveBarrierChoose(int num) {
        
    }

    static void resolveInvalidInput() {
        std::cout << "Invalid Input" << std::endl;
    }

};
#endif