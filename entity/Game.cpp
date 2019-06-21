#include"Game.h"
#include<assert.h>
Session* Game::startSession(std::string head) {
        assert(currentSession == NULL);
        mapHead = head;
        std::string path = "./maps/" + mapHead + ".map";
        currentSession = new Session(path);
        return currentSession;
    }

Session* Game::nextSession() {
        int mapNum;
        sscanf(mapHead.c_str(), "%d", &mapNum);
        mapNum++;
        mapNum %= 9;
        mapHead = std::to_string(mapNum);
        return startSession(mapHead);
    }

void Game::finishSession() {
        delete currentSession;
        currentSession = NULL;
    }