#include "Player.h"
#include <cstdlib>

Player::Player(string n, int a)
{
	score = 501; // 501 darts therefore 501 points
	name = n;
	successRate = a;
}

// creates the player object

int Player::getScore() {

	return(score);

}

void Player::setScore(int x) {

	score = x; // sets the score to whatever is input 

}

// getters and setters

int Player::throwBull() {

	//  Throw for the bull with percent accuracy (20<p<85)

	int random = rand() % 100 + 1;

	if (random <= (successRate - 20))
	{
		return 50;
	}
	else if (random <= 85)
	{
		return 25;
	}
	else
	{
		return rand() % 20 + 1;
	}
}



int Player::throwTreble(int p) {

	//  return result of throwing for treble d with accuracy p%  (o<90)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };

	int r = rand() % 100 + 1;

	if (r <= successRate)
		return 3 * p;
	else if (r <= 90)
		return p;
	else if (r <= 93)
		return 3 * bd[0][p];
	else if (r <= 96)
		return 3 * bd[1][p];
	else if (r <= 98)
		return bd[0][p];
	else
		return bd[1][p];
}


int Player::throwDouble(int d) {

	//  return result of throwing for double d with accuracy 80%

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;

	if (r <= 80)
		return 2 * d;
	else if (r <= 85)
		return 0;
	else if (r <= 90)
		return d;
	else if (r <= 93)
		return 2 * bd[0][d];
	else if (r <= 96)
		return 2 * bd[1][d];
	else if (r <= 98)
		return bd[0][d];
	else
		return bd[1][d];
}



int Player::throwSingle(int d) {

	//  return result of throwing for single d with accuracy 88% (or 80% for the outer bullseye)

	// Board neighbours ignoring slot zero
	int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
			   {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
	int r = rand() % 100 + 1;

	if (d == 25) {		// outer bullseye has success rate of 80%
		if (r <= 80)
			return 25;
		else if (r <= 90)
			return 50;
		else
			return rand() % 20 + 1;
	}
	else			// we must be aiming for 1 to 20 single
		if (r <= 88)
			return d;
		else if (r <= 92)
			return bd[0][d];
		else if (r <= 96)
			return bd[1][d];
		else if (r <= 98)
			return 3 * d;
		else
			return 2 * d;
}