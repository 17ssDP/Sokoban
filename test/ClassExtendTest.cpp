#include "../entity/Element.cpp"
#include "../entity/Object.cpp"
#include "../entity/Player.cpp"
#include "../entity/Box.cpp"
#include "../entity/Position.cpp"
#include "../entity/Symbol.cpp"
#include<map>
using namespace std;

int main() {
    Position *pos1 = new Position(1, 2);
    Player *player = new Player(*pos1);
    Position *pos2 = new Position(2, 3);
    Box *box = new Box(*pos2);
    Player player1(*pos1);
    player1.getSymbol();

    player->move(*pos2);

    map<Position, Element> eleMap;
    eleMap.insert(pair<Position, Element>(*pos1, *player));
    if(eleMap.find(*pos1)->second.getSymbol() == Persion)
        cout << "Persion" << endl;

    delete pos1;
    delete player;
    delete pos2;
    delete box;
}