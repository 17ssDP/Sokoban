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

    static void display(Map eleMap) {
        eleMap.print();
    }

    static void resolveInput(Game* game, Player* player) {
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
            resolveMove(game, player, order);
            break;
        case 'Q':
            exit(0);
        case 'H':
            resolveHelp();
            break;
        case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
            resolveBarrierChoose(game, input);
            break;
        default:
            resolveInvalidInput();
            break;
        }
    }

    static void resolveMove(Game* game, Player* player, const char move) {
        Position pos;
        switch (move)
        {
        case 'W':
            pos = Position(-1, 0);
            break;
        case 'A':
            pos = Position(0, -1);
            break;
        case 'S':
            pos = Position(1, 0);
            break;
        case 'D':
            pos = Position(0, 1);
            break;
        default:
            pos = Position(0, 0);
        }
        if(player->validMove(*game->getCurrentSession()->getMap(), pos)) {
            player->move(game->getCurrentSession()->getMap(), pos);
        }
    }

    static void resolveHelp() {
        std::cout << "Help" << std::endl;
    }

    static void resolveBarrierChoose(Game* game, std::string num) {
        game->finishSession();
        game->startSession(num);
    }

    static void resolveInvalidInput() {
        std::cout << "Invalid Input" << std::endl;
    }

};
#endif