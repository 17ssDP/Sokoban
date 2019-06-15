#ifndef GAME
#define GAME 
#include<vector>
#include<assert.h>
#include"Session.cpp"
class Game
{
private:
    std::vector<Session> sessions;
    Session *currentSession;
public:
    Game(/* args */) {
        currentSession = NULL;
    }

    const Session& startSession(std::string path) {
        assert(currentSession == NULL);
        currentSession = new Session(path);
        return *currentSession;
    }

    void finishSession() {
        delete currentSession;
        currentSession = NULL;
    }
    ~Game();
};

#endif