#ifndef GAME_H
#define GAME_H
#include<vector>
#include<string>
#include"Session.h"
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
    Session* startSession(std::string head);
    Session* nextSession();
    void finishSession();
    ~Game() {

    }
};

#endif