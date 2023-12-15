#include <iostream>
#pragma once


using namespace std;

class Player {
private:
	int score;
	int successRate;
	int throws;
	string name;
	// things that are not accessible by the game etc, so player information
public:
	Player(string, int); // creates a player
	int getScore();
	void setScore(int);
	int throwBull();
	int throwSingle(int);
	int throwDouble(int);
	int throwTreble(int);
};