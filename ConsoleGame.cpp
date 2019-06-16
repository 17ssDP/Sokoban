#include"./entity/Game.cpp"
#include"./entity/Player.cpp"
#include"./util/ConsoleGameUtil.cpp"
#include<iostream>
#include<map>
using namespace std;

int main() {
    Game *game = new Game();
    Session* session = game->startSession("2");
    Player* player = new Player(*session->getMap());
    ConsoleGameUtil::display(*session->getMap());
    // game->finishSession();
    // cout << game->getCurrentSession()->finished() << endl;
    // while(!game->getCurrentSession()->finished()) {
    //     ConsoleGameUtil::resolveInput(game, player);
    //     ConsoleGameUtil::display(*session->getMap());
    // }
    // game->finishSession();
}