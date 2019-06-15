#include"./entity/Game.cpp"
#include"./util/ConsoleGameUtil.cpp"
#include<iostream>
#include<map>
using namespace std;

int main() {
    Game *game = new Game();
    Session session = game->startSession("./maps/2.map");
    
    // game->startSession("./maps/2.map");
    ConsoleGameUtil::display(session.getMap());
    ConsoleGameUtil::resolveInput();
    game->finishSession();
}