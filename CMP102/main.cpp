#include <iostream>
#include <cstdlib>    // random numbers header file
#include "Game.h" 
#include <Windows.h> // using for CLS
using namespace std;

string p1Name, p2Name;
int p1SR, p2SR;
void startGame(), interGame();

//defining all of our variables, also define the functions before we use them 

int main()
{
	bool active = true;
	while (active == true) // keep bringing up the menu
	{
		int choice;
		cout << "Welcome to 501 darts. Please select what you would like to do" << endl;
		cout << "1. Start a regular game" << endl;
		cout << "2. Start an interactive game" << endl;
		cout << "3. Exit"<< endl;
		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			active = false; // stop the menu from coming back up
			startGame(); // start the game
		}
		else if (choice == 2)
		{
			active = false; // stop the menu from coming back up
			interGame(); // start an interactive game
		}
		else if (choice == 3)
		{
			exit(0); // exit
		}
		else
		{
			cout << "That was an invalid option. Please try again!"; // active = true therefore load the menu again
			system("CLS"); // clear the screen, stops it getting cluttered up
		}
	}
	
	return 0;
}


void startGame()
{
	system("CLS"); // clear the screen
	string p1Name, p2Name;
	int p1SR, p2SR;

	//define our variables
	cout << "Player 1, please enter your name: ";
	cin >> p1Name;
	cout << "Player 2, please enter your name: ";
	cin >> p2Name;

	cout << p1Name << " please enter your success rate: ";
	cin >> p1SR;
	cout << p2Name << " please enter your success rate: ";
	cin >> p2SR;

	// get all the neccesary information from our players
	Game game(p1Name, p1SR, p2Name, p2SR);
	// initiate a game for 2 players with their successrate and names
	if (game.getWinner() == 1) // if the winner = 1 then p1 won, so tell the player that
	{
		cout << "Congratulations to " << p1Name << " on winning the game!" << endl;
		cout << p2Name << " came 2nd with a score of " << game.p2GetScore() << endl;
	}
	else // otherwise the 2nd player
	{
		cout << "Congratulations to " << p2Name << " on winning the game!" << endl;
		cout << p1Name << " came 2nd with a score of " << game.p1GetScore() << endl;
	}
	Sleep(10000); // wait 10 seconds
	system("CLS"); // clear the screen
	main(); // show the menu
}

void interGame()
{
	system("CLS");
	cout << "Please enter your name ";
	cin >> p1Name;
	cout << "Please enter your success rate ";
	cin >> p1SR;
	/// since this is an interactive game they are against the AI so only need one person's info
	cout << "Please enter The Computer's success rate ";
	cin >> p2SR;

	// get the AI's SR
	system("CLS");

	// clear the screen
	Game game(p1Name, p1SR, p2SR);


	// initiate a game using a a different overloaded constructor
	if (game.getWinner() == 1)
	{
		cout << "Congratulations to " << p1Name << " on winning the game!"<< endl;
		cout << "The computer came 2nd with a score of " << game.p2GetScore() << endl;
	}
	else
	{
		cout << "Congratulations to The Computer on winning the game!"<< endl;
		cout << p1Name << " came 2nd with a score of " << game.p1GetScore() << endl;
	}

	main();

}