#include <iostream>
#include "Player.h"

using namespace std;


class Game {

private:
	bool running = false;

	int currentPlayer, winner, p1Score, p2Score;



public:
	Game(string, int, string, int); // 2 players
	Game(string, int, int); // player vs ai


	// funcs 
	int switchPlayer(Player&, Player&, int);
	int turn(Player&, Player&);
	int interactiveTurn(Player&, Player&);
	int endTurnCheck(int, Player&, Player&);
	int endGame(Player&, Player&);

	// getters and setters
	void setActivePlayer(bool);
	bool getActivePlayer();
	void setCurrentPlayer(int a);
	int getCurrentPlayer();
	void setWinner(int x);
	int getWinner();
	void p1SetScore(int a);
	int p1GetScore();
	void p2SetScore(int a);
	int p2GetScore();


};