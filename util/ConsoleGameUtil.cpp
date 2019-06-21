#ifndef CONSOLEGAME_UTIL
#define CONSOLEGAME_UTIL
#include"../entity/Symbol.h"
#include"../entity/Map.h"
#include"../entity/Game.h"
#include"../entity/Player.h"
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
        std::cout << "♀ 代表小人儿，▓代表墙体，□代表箱子，○代表目标地点，当你把箱子推到目标地点之后，□就会变成■" << std::endl;
        std::cout << "来呀来呀，来玩呀" <<std::endl;
        std::cout << "H代表帮助，输入1-9选择关卡，输入Q退出游戏"<< std::endl;
    }

    static void resolveBarrierChoose(Game* game, std::string num) {
        game->finishSession();
        startOneSession(game, num);
    }

    static void resolveInvalidInput() {
        std::cout << "Invalid Input" << std::endl;
    }

    static std::string chooseNewMap() {
        std::string input;
        getline(std::cin, input);
        if(input.length() != 1) {
            resolveInvalidInput();
            return chooseNewMap();
        }
        char order = input.at(0);
        if(order == 'Q') {
            exit(0);
        }
        if(order == 'H') {
            resolveHelp();
        }
        if(order >= '1' && order <= '9') {
            return input;
        }
        resolveInvalidInput();
        return chooseNewMap();
    }

    static void playOneSession(Game* game){
        Session* currentSession = game->getCurrentSession();
        Player player(*currentSession->getMap());
        while(!currentSession->finished()) {
            display(*currentSession->getMap());
            resolveInput(game, &player);
        }
        display(*currentSession->getMap());
        finishOneSession(game);
    }

    static void finishOneSession(Game* game) {
        std::cout << "Victory!!! Choose a new map: ";
        game->finishSession();
        std::string num = chooseNewMap();
        startOneSession(game, num);
    }

    static void startOneSession(Game* game, std::string num = "1") {
        game->startSession(num);
        playOneSession(game);
    }
};
#endif