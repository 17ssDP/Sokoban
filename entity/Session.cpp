#ifndef SESSION
#define SESSION
#include "Map.cpp"
#include "../util/FileUtil.cpp"
class Session
{
private:
    Map map;
public:
    Session() {
        
    }
    Session(std::string path) {
        map = Map(path);
    }
    int finished() const {

    }
    const Map getMap() const {
        return map;
    }
    ~Session();
};

Session::~Session()
{
}

#endif //SESSION