#ifndef GAME
#define GAME 
#include<vector>
#include<assert.h>
#include<string>
#include"Session.cpp"
class Game
{
private:
    std::vector<Session> sessions;
    Session *currentSession;
    std::string mapHead;
public:
    Game(/* args */) {
        currentSession = NULL;
    }

    Session* getCurrentSession() {
        return currentSession;
    }

    Session* startSession(std::string head) {
        assert(currentSession == NULL);
        std::string path = "./maps/" + head + ".map";
        currentSession = new Session(path);
        return currentSession;
    }

    Session* nextSession() {
        int mapNum;
        sscanf(mapHead.c_str(), "%d", &mapNum);
        mapNum = (mapNum + 1) / 9;
        if(mapNum == 0)
            mapNum = 9;
        mapHead = to_string(mapNum);
        return startSession(mapHead);
    }

    void finishSession() {
        delete currentSession;
        currentSession = NULL;
    }
    ~Game();
};

#endif