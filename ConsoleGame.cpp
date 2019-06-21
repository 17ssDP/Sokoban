#include"./entity/Game.h"
#include"./entity/Player.h"
#include"./util/ConsoleGameUtil.cpp"
#include<iostream>
#include<map>
using namespace std;

static void startOneSession(Game* game, string num);
static void playOneSession(Game* game);
static void finishOneSession(Game* game);

void playGame(Game* game);

int main() {
    Game *game = new Game();
    playGame(game);
    delete game;
}

void playGame(Game* game) {
    ConsoleGameUtil::resolveHelp();
    ConsoleGameUtil::startOneSession(game);
}