#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;


// Defining our global variables
int HUNGER = 4, SLEEP = 4, PLAY = 4, HAPPINESS = 4;


void setup()
{
	cout << "Please pick what kind of pet you would like:" << endl << "1. Dog" << endl << "2. Cat" << endl << "3. Hamster" << endl << endl << "Please pick a pet: ";
	int choice; cin >> choice; // Defining variable and asking the user for an input

	string fileToOpen; // To be used for opening a specific file
	if (choice == 1)
	{
		fileToOpen = "woof.txt";
		SLEEP = 2, HUNGER = 3, HAPPINESS = 5;
	}
	else if (choice == 2)
	{
		fileToOpen = "meow.txt";
		SLEEP = 5, HUNGER = 1, HAPPINESS = 2;
	}
	else if (choice == 3)
	{
		fileToOpen = "nibble.txt";
		PLAY = 5;
	}
	else
	{
		setup();
	}
	// Depending on the pet type we can change the starting attributes of the pet, adding more diversity to it
	ifstream file;
	string x;
	file.open(fileToOpen);
	do {
		cout << x << endl;
	} while (getline(file, x));

	file.close();
	// Opening a file and reading through every line in said file, before closing the file

	char temp;string petName;
	cout << endl << "\x1B[31mWould you like to name your pet? (Y/N) \033[0m";
	cin >> temp; temp = toupper(temp);

	if (temp == 'Y')
	{
		cout << "\x1B[36mWhat would you like your pet's name to be? \033[0m ";
		cin >> petName;
	}
	else
	{
		petName = "your pet";
	}

	// Giving the user the option to name their pet otherwise defaulting it to "your pet"

	cout << "\x1B[36mHere is your pet: \033[0m" << endl;
	file.open(fileToOpen);
	if (file.is_open())
	{
		while (getline(file, x))
		{
			cout << x << endl;
		}
	}
	file.close();
	cout << "\x1B[36mNametag:\033[0m " << petName << endl << endl;

	// Outputting an overview of the user's pet
	int menu(string petName, int debuff);
	menu(petName, 1);
}

int petHappy(string petName)
{
	HAPPINESS++;
	if (HAPPINESS <= 0) { // Instead of using a healthcheck function, if the value = 0
		cout << petName << " died of boredom." << endl;
		exit(1);
	}
	else if (HAPPINESS = 1)
	{
		cout << petName << " could be better" << endl;
	}
	else if (HAPPINESS = 2)
	{
		cout << petName << " is alright" << endl;
	}
	else if (HAPPINESS = 3)
	{
		cout << petName << " is joyful" << endl;
	}
	else if (HAPPINESS = 4)
	{
		cout << petName << " is already at their maximum happiness" << endl;
	}
	else if (HAPPINESS > 4)
	{
		cout << petName << " is already at their maximum happiness" << endl;
		HAPPINESS--; // If they're already really happy and you try to make them happier, reduce their happiness because you're overdoing this thing with them
	}
	int menu(string petName, int debuff); // We have to define it here 
	menu(petName, 1);
	return HAPPINESS, 1;
}

int petPlay(string petName)
{
	PLAY++;
	if (PLAY <= 0) {
		cout << petName << " died due to a lack of enjoyment." << endl;
		exit(1);
	}
	else if (PLAY == 1) {
		cout << petName << " is not interested" << endl;
	}
	else if (PLAY == 2) {
		cout << petName << " is interested in playing" << endl;
	}
	else if (PLAY == 3) {
		cout << petName << " is really interested in playing" << endl;
	}
	else if (PLAY == 4) {
		cout << petName << " is feeling really playful" << endl;
	}
	else if (PLAY > 4) {
		cout << petName << " is already really playful" << endl;
		PLAY--;
	}
	int menu(string petName, int debuff);
	menu(petName, 1);

	return PLAY, 1;

}

int petNap(string petName)
{
	SLEEP++;
	if (SLEEP <= 0) {
		cout << petName << " died due to a lack of sleep." << endl;
		exit(1);
	}
	else if (SLEEP == 1) {
		cout << petName << " is starting to fall asleep" << endl;
	}
	else if (SLEEP == 2) {
		cout << petName << " is now tired" << endl;
	}
	else if (SLEEP == 3) {
		cout << petName << " is now awake" << endl;
	}
	else if (SLEEP == 4) {
		cout << petName << " is wide awake" << endl;
	}
	else if (SLEEP > 4) {
		cout << petName << " is already wide awake" << endl;
		SLEEP--;
	}
	int menu(string petName, int debuff);
	menu(petName, 1);

	return SLEEP, 1;

}

int petFeed(string petName)
{
	HUNGER++; // Feeds the pet
	// Goes through if and elif statements checking what the hunger currently is
	// and outputs something accordingly 

	if (HUNGER <= 0) {
		cout << petName << " died due to a lack of hunger." << endl;
		exit(1);
	}
	else if (HUNGER == 1) {
		cout << petName << " is starving" << endl;
	}
	else if (HUNGER == 2) {
		cout << petName << " is rather hungry" << endl;
	}
	else if (HUNGER == 3) {
		cout << petName << " is slightly peckish" << endl;
	}
	else if (HUNGER == 4) {
		cout << petName << " is well fed" << endl;
	}
	else if (HUNGER > 4) {
		cout << petName << " is already well fed" << endl;
		HUNGER--; // keep it within boundaries
	}

	int menu(string petName, int debuff);

	menu(petName, 1);
	return HUNGER, 1;

}

void petStatus(string petName)
{
	int total = HAPPINESS + HUNGER + SLEEP + PLAY;
	cout << petName << " is currently rated: " << total << "/" << "16" << endl;

	// Large output so do it line by line for sanity sake
	cout << "This is currently split by: " << endl << endl;
	cout << "\x1B[33mHunger: \033[0m" << HUNGER << "/" << "4" << endl;
	cout << "\x1B[36mSleep: \033[0m" << SLEEP << "/" << "4" << endl;
	cout << "\x1B[31mPlay: \033[0m" << PLAY<< "/" << "4" << endl;
	cout << "\x1B[32mHappiness: \033[0m" << SLEEP << "/" << "4" << endl;
	// The text that describes each attribute might look weird but it's just colour coded
	int menu(string petName, int debuff);
	menu(petName, 1);
}

int menu(string	petName, int debuff)
{
	if (debuff == 1)
	{
		int roll; roll = rand() % 6 + 1; // selecting a random number between 1 and 6
		if (roll == 3) { // if the random number is three then reduce one of each statistic
			HUNGER--, SLEEP--, PLAY--, HAPPINESS--;
		}
	}
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	int choice;
	cout << "Welcome to your cyberPet! Here is the menu: " << endl << "1. Feed" << endl << "2. Take a Nap" << endl << "3. Play" << endl << "4. Overall Happiness" << endl << "5. Display Current State" << endl << "6. Quit" << endl << endl << "\x1B[36mPlease input your choice: \033[0m ";
	cin >> choice;

	if (choice == 1) {
		int petFeed(string petName);
		petFeed(petName);
	}
	else if (choice == 2) {
		int petNap(string petName);
		petNap(petName);
	}
	else if (choice == 3) {
		int petPlay(string petName);
		petPlay(petName);
	}
	else if (choice == 4) {
		int petHappy(string petName);
		petHappy(petName);
	}
	else if (choice == 5) {
		void petStatus(string petName);
		petStatus(petName);
	}
	else if (choice == 6) {
		exit(1);
	}
	else
	{
		menu(petName, 0);
	}
	return 0;
}


int main()
{
	setup();
}
