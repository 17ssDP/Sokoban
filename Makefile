CPP=g++
BIN=./bin
ENTITYDIR=./entity

all:ConsoleGame
ConsoleGame:Game Map Player Session ConsoleGame.cpp
	$(CPP) ConsoleGame.cpp -o ConsoleGame.exe $(BIN)/Game.o $(BIN)/Map.o $(BIN)/Player.o $(BIN)/Session.o
Game:$(ENTITYDIR)/Game.cpp
	$(CPP) -c $< -o $(BIN)/$@.o
Map:$(ENTITYDIR)/Map.cpp
	$(CPP) -c $< -o $(BIN)/$@.o
Session:$(ENTITYDIR)/Session.cpp
	$(CPP) -c $< -o $(BIN)/$@.o
Player:$(ENTITYDIR)/Player.cpp
	$(CPP) -c $< -o $(BIN)/$@.o
clean:
	rm $(BIN)/*