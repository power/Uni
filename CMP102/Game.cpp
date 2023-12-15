#include "Game.h"
#include <iostream>
#include <cctype>


using namespace std;


// single sim
Game::Game(string p1Name, int p1SR, string p2Name, int p2SR)
{
	Player player1(p1Name, p1SR);
	Player player2(p2Name, p2SR);

	setActivePlayer(true);

	switchPlayer(player1, player2, 1);

}

//interactive game
Game::Game(string p1Name, int p1SR, int p2SR)
{
	Player player1(p1Name, p1SR);
	Player player2("The Computer", p2SR);

	setActivePlayer(true);

	switchPlayer(player1, player2, 0);
}


int Game::switchPlayer(Player& player1, Player& player2, int a)
{
	if (a == 1)
	{
		while (getActivePlayer() == true)
		{
			setCurrentPlayer(1);

			int currentTurn = turn(player1, player2);
			if (currentTurn != 10)
			{
				setCurrentPlayer(2);
				turn(player2, player1);
			}
		}
	}
	else
	{
		while (getActivePlayer() == true)
		{
			setCurrentPlayer(1);

			int currentTurn = turn(player1, player2);
			if (currentTurn != 10)
			{
				setCurrentPlayer(2);
				interactiveTurn(player2, player1);
			}
		}
	}

	return 0;
}


int Game::turn(Player& p1, Player& p2)
{
	int throws = 0; // temporary response from aiming at points on the board

	for (int i = 0; i < 3; i++)
	{
		int score = p1.getScore(); // current score
		if (score > 61) 
		{
			// Aim for triple 20
			throws = p1.throwTreble(20); // aim for triple 20, trying to get rid of the largest amount
			score -= throws; // remove the response from the total
			if (endTurnCheck(score, p1, p2) == 0)
			{
				break; // if score is negative, exit loop
			}
		}

		else if (score >= 50 && score <= 61)
		{
			// if player needs bullseye to win
			throws = p1.throwBull(); 
			score -= throws;
			if (endTurnCheck(score, p1, p2) == 0)
			{
				break; // score is negative, exit loop
			}
			else
			{
				return 10; // game is won
			}
		}

		else if (score > 41 && score < 50)
		{
			// if score is > 40 but less then 50
			throws = p1.throwDouble(20); // aim double 20
			score -= score;
			if (endTurnCheck(score, p1, p2) == 0)
			{
				break; // if score is negative
			}
		}

		else if (score == 1)
		{
			// do nothing since 1 is left
		}

		else if (score % 2 != 0 && score >= 23 && score < 40)
		{
			int temp = score / 2;
			temp--;
			throws = p1.throwDouble(temp);
			score -= score;
			if (endTurnCheck(score, p1, p2) == 0)
			{
				break;
			}
		}

		else if(score % 2 != 0)
		{
			throws = p1.throwSingle(score - 2);
			score -= score;

			if (endTurnCheck(score, p1, p2) == 0)
			{
				break;
			}
		}

		else
		{
			throws = p1.throwDouble(score / 2);
			score -= score;
			if (endTurnCheck(score, p1, p2) == 0)
			{
				break;
			}
			else if (endTurnCheck(score, p1, p2) == 10)
			{
				return 10;
			}
		}
	}
	return 0;
}

int Game::interactiveTurn(Player& p1, Player& p2)
{
	int throws = 0; // temp score holder
	for (int i = 0; i < 3; i++)
	{
		int score = p1.getScore();
		int aim;
		bool check = false;
		// defining variables

		cout << "Your current score is: " << score << " vs The Computer: " << p2.getScore() << endl;
		cout << "Please choose what number you would like to aim for on the board (1-20 or 50): ";
		cin >> aim;

		// ask the user what the ywant to aim for
		while (check == false) // while loop used for aiming exclusively for a bullseye
		{
			if (aim == 50)
			{
				throws = p1.throwBull();
				cout << "Hit:" << throws << endl;
				score -= throws;
				p1.setScore(score);
				if (endTurnCheck(score, p1, p2) == 0)
				{
					break;
				}
				else if (endTurnCheck(score, p1, p2) == 0)
				{
					return 10;
				}
				check = true;
			}
			else if (aim >= 1 && aim <= 20)
			{
				check = true; // choice was valid and wasnt bullseye
			}
			else
			{
				cout << "You chose an invalid number. Please try again."; // choice wasn't 1-20 or 50 so try again
				cin >> aim;
			}
		}
		if (aim != 50) // dont want this code to execute if the player aimed for a bullseye since you cant aim for a D/T bullseye
		{
			char aimtype;
			cout << "Please input whether you want to aim for a Single (S), Double (D) or Triple (T): "; // if the user didnt aim for the bullseye
			cin >> aimtype;
			aimtype = tolower(aimtype); // convert it to lower to make our statement shorter and easier

			check = false;
			while (check == false)
			{
				if (aimtype == 's' || aimtype == 'd' || aimtype == 't') // make sure the type is  valid
				{
					check = true;
				}
				else // choice was invalid, try again
				{
					cout << "That was an invalid input. Please try again.";
					cin >> aimtype;
				}


				if (aimtype == 's') // if aiming for single
				{
					throws = p1.throwSingle(aim); // throw at single
					cout << "Hit: " << throws << endl; // tell them what they hit
					score -= throws; // take from total
					p1.setScore(score); // set their score to it
					if (endTurnCheck(score, p1, p2) == 0)
					{
						break; // if score is negative, break
					}
				}

				else if (aimtype == 'd')// if aiming for double
				{
					throws = p1.throwDouble(aim); // throw at double
					cout << "Hit: " << throws << endl; // tell them what they hit
					score -= throws; // take from total
					p1.setScore(score); // set their score to it
					if (endTurnCheck(score, p1, p2) == 0)
					{
						break; // if score is negative
					}
				}
				else // aiming for triple
				{
					throws = p1.throwTreble(aim); // throw for triple
					cout << "Hit: " << throws << endl; // tell them what they hit
					score -= throws; // take from total
					p1.setScore(score); // set their score to it
					if (endTurnCheck(score, p1, p2) == 0)
					{
						break; // if score is negative
					}
				}
			}
		}
	}
	return 0;
}


int Game::endTurnCheck(int score, Player& p1, Player& p2)
{
	if (score == 0) // if they have 0 they have won
	{
		p1.setScore(score); // set the score to 0
		if (getActivePlayer() == 1) // if p1 is the active player
		{
			setActivePlayer(false); // set it to false
			endGame(p1, p2); // end the game with p1 as the winner
		}
		else
		{
			setActivePlayer(false);
			endGame(p2, p1); // end the game with p2 as the winner
		}

		return 10;
	}

	else if (score <= 1)
	{
		return 0; // program handles the response and knows to cancel the turn
	}

	else
	{
		p1.setScore(score); // the shot is fine
		return 1;
	}
}

int Game::endGame(Player& p1, Player& p2)
{
	p1SetScore(p1.getScore());
	p2SetScore(p2.getScore());

	// passing the scores through the game function to the player function so it can be called in main
	if (p1.getScore() == 0)
	{
		setWinner(1); // set winner as p1
	}
	else
	{
		setWinner(2); // set winner as p2
	}

	return 0;
}




// getters and setters
void Game::setActivePlayer(bool a)
{
	running = a;
}

bool Game::getActivePlayer()
{
	return (running);
}

void Game::setCurrentPlayer(int a)
{
	currentPlayer = a;
}

int Game::getCurrentPlayer()
{
	return (currentPlayer);
}

void Game::setWinner(int a)
{
	winner = a;
}

int Game::getWinner()
{
	return (winner);
}


int Game::p1GetScore() {

	return(p1Score);

}

void Game::p1SetScore(int a) {

	p1Score = a;

}

int Game::p2GetScore() {

	return(p2Score);

}

void Game::p2SetScore(int a) {

	p2Score = a;

}
