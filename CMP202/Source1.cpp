#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <semaphore>
#include <cstring>

// the above libraries are used for the functionality of this program

using std::cout;
using std::cin;
using std::endl;
using std::thread;
using std::string;

// due to their usage through the program it was easier to define these specific things here to save typing it out every time

std::condition_variable signal;
std::mutex lock;
int global_counter;

// global variables that are used throughout the program

string encrypt(string key, string password)
{
	string encryptedText; // temporary variable that stores the encrypted text as it is converted
	int key_position = 0; // makes note of the position the loops are through the key is not long enough
	for (int counter = 0; counter < password.length(); ++counter) // for the length of the text that is going to be encrypted
	{
		char temp_char = password[counter]; // store it as a temporary character
		if (temp_char >= 'a' && temp_char <= 'z') // if it a lowercase character
		{
			temp_char += 'A' - 'a'; // add the ascii value of A - a to whatever the ASCII value of the character is
		}
		else if (temp_char >= '0' && temp_char <= '9') // if the character is a number
		{
			encryptedText.push_back(temp_char); // vignere cipher will not work on numbers so add it to the encrypted password
			key_position = (key_position + 1) % key.length(); // indicate to the program that it has moved onto the next character so it doesn't break on numbers
			continue; // continue on with the program
		}
		else if (temp_char < 'A' || temp_char > 'Z') // if the character's ASCII value is less then A or greater then Z 
		{
			continue; // ASCII values either side of A or Z are not converted in a vignere cipher so continue
		}

		temp_char = (temp_char + key[key_position] - 2 * 'A') % 26 + 'A'; // rotate the character 
		encryptedText.push_back(temp_char); // push it to the back of the string
		key_position = (key_position + 1) % key.length(); // move onto the next character in the string to be converted
	}
	return encryptedText; // return the finished text once complete
}

string decrypt(string key, string password)
{
	// code for this function is the same as the encrypt function, just reversed as we are doing the opposite
	string decryptedText; 
	int key_position = 0; 
	for (int counter = 0; counter < password.length(); ++counter)
	{
		char temp_char = password[counter];
		if (temp_char >= 'a' && temp_char <= 'z')
		{
			temp_char += 'A' - 'a';
		}
		else if (temp_char >= '0' && temp_char <= '9')
		{
			decryptedText.push_back(temp_char);
			key_position = (key_position + 1) % key.length();
			continue;
		}
		else if (temp_char < 'A' || temp_char > 'Z')
		{
			continue;
		}

		temp_char = (temp_char - key[key_position] + 26) % 26 + 'A';
		decryptedText.push_back(temp_char);
		key_position = (key_position + 1) % key.length();
	}

	return decryptedText;
}

string cracker(string key, string encrypted, std::vector<string> vOfData, int start_point, int end_point, int line_count)
{
	string current; // define a variable which will store the contents of the current password being checked

	for (start_point; start_point < end_point; ++start_point) // for as many passwords that are being checked by this thread
	{
		current = vOfData[start_point]; // store the current password into this variable
		string encrypted_test = encrypt(key, current); // encrypt it
		//DEBUGGING - std::cout << "The encrypted password is " << (encrypted_test) <<  " line: " << start_point << endl;
		if (encrypted_test == encrypted) // if the encrypted version of current = the users password
		{
			string decryptedText = decrypt(key, encrypted); // decrypt the users pasword
			std::cout << "The decrypted password is " << decryptedText << endl; // output what it is
			global_counter = line_count; // indicate to the timing thread (if running) that it does not need to wait anymore
			signal.notify_all(); // tell the other threads to stop
			break; // break out of the for loop
		}

		++global_counter; // if current != password, increase the counter by one
	}
	return encrypted;
}

std::vector<string> fileToVector()
{
	string lineData; // creates a temporary variable that will store the contents of one line
	std::vector<string> vOfData; // a vector of strings that will store the contents of the file
	std::ifstream rockyou("rockyou.txt"); // opens the file that the user is wanting to use
	while (rockyou.peek() != EOF) // whilst there is another line in the file
	{
		std::getline(rockyou, lineData); // get the line and store it into the lineData variable
		vOfData.push_back(lineData); // and add it to the vecot
	}

	return vOfData; // return the vector when this is complete so that it can be used elsewhere
}


void timeCalc(int line_count) // how to implement this?
{
	std::unique_lock<std::mutex> uq(lock); // create a unique mutex lock so that signalling will work
	/*
	cracker threads should have a counter which is checked, wait until it equals that value and then signal to continue here, 
	set it to = that value if pw is found
	*/
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); // when this thread is started, start the lock
	while (global_counter != line_count) // whilst the global_counter hasn't reached the end of the program, or hasn't been changed to be at the end
		signal.wait(uq); // wait here, do not continue
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now(); // once it is allowed to continue, note the time

	int time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count(); // calculate the time taken between starting the timing thread and ending it
	cout << "It took " << time_taken << "ms to crack your password." << endl; //output this time
}


void menu()
{
	int choice = 0; // defines a variable which can be used to store the users choice

	cout << "What would you like to do? \n 1. Crack a password \n 2. Mass test threads \n Option: ";
	cin >> choice; // store the users choice

	/*if (choice == 1) // if the user chooses just to crack their password without timing it
	{
		string key;
		string password;
		int threads_in_use;

		// variables that will be used to store user input
		
		bool pCheck = false; // variable used for checking whether the users password is in the wordlist
		int line_count = 0; // variable for keeping count of how many lines are in the text file
		cout << "Please input a key: "; 
		cin >> key; // store the users key
		std::transform(key.begin(), key.end(), key.begin(), ::toupper); // conver it to uppercase to ensure the encrypt & decrypt functions work
		cout << "How many threads would you like to use? ";
		cin >> threads_in_use; // store how many threads the user wants to use



		string temp_line; // create a temporary variable for storing the current line
		while (pCheck == false) // whilst the password hasn't been checked
		{
			cout << "Please input your password from rockyou: "; // ask the user for a password
			cin >> password; // store it
			std::ifstream rockyou("rockyou.txt"); // open the wordlist
			while (rockyou.peek() != EOF) // whilst there is another line in the file
			{
				std::getline(rockyou, temp_line); // get the current line and store it in temp_line
				if (temp_line == password) // if it matches the users password
				{
					pCheck = true; // the users password is in the wordlist, the program can continue
				}
				++line_count; // increase the word count
			}
			rockyou.close(); // close the file
		}

		string encrypted_password = encrypt(key, password); // encrypt the users password
		
		int line_incrementer = round(line_count / threads_in_use); // figure out how many lines each thread will need to complete to reach the end of the file
		int starting_line = 0;
		int ending_line = 0;

		// variables used for sorting out the work required by each thread

		std::vector<string> vOfData = fileToVector(); // executes the fileToVector function
		auto* myCrackerThreads = new std::thread[threads_in_use]; // creates as many threads as the user has requested


		for (int counter = 0; counter < threads_in_use; ++counter) // for as many threads as the user has requested
		{

			ending_line += line_incrementer; // increase the ending line of each thread by the same value
			myCrackerThreads[counter] = std::thread(cracker, key, encrypted_password, vOfData, starting_line, ending_line, line_count);
			// run a new thread that will run the cracker function and takes the key, encrypted password, vector of data, starting and finishing line and total length of the file
			starting_line = ending_line; // set the starting line to equal the ending line so when the loop runs again, there is always a new ending line
		}

		for (int i = 0; i < threads_in_use; ++i) // for as many threads as requested
		{
			myCrackerThreads[i].join(); // join the threads
		}


	}*/
	if (choice == 1)
	{
		string key;
		string password;
		int threads_in_use;
		bool pCheck = false;
		int line_count = 0;
		cout << "Please input a key: ";
		cin >> key;
		cout << "How many threads would you like to use? ";
		cin >> threads_in_use;
		std::transform(key.begin(), key.end(), key.begin(), ::toupper);


		string temp_line;
		while (pCheck == false)
		{
			cout << "Please input your password from rockyou: ";
			cin >> password;
			std::ifstream rockyou("rockyou.txt");
			while (rockyou.peek() != EOF)
			{
				std::getline(rockyou, temp_line);
				if (temp_line == password)
				{
					pCheck = true;
				}
				++line_count;
			}
			rockyou.close();
		}

		string encrypted_password = encrypt(key, password);

		int line_incrementer = round(line_count / threads_in_use);
		int starting_line = 0;
		int ending_line = 0;



		std::vector<string> vOfData = fileToVector();
		auto* myCrackerThreads = new std::thread[threads_in_use];
		
		// up to this point, the code for choice 1 and choice 2 are identical
		
		thread myPrepThreads[1];
		myPrepThreads[0] = std::thread(timeCalc, line_count);
		
		// create a thread that starts recording the time it takes for the rest of the program to execute

		for (int counter = 0; counter < threads_in_use; ++counter)
		{

			ending_line += line_incrementer;
			myCrackerThreads[counter] = std::thread(cracker, key, encrypted_password, vOfData, starting_line, ending_line, line_count);
			starting_line = ending_line;
		}

		for (int i = 0; i < threads_in_use; ++i)
		{
			myCrackerThreads[i].join();
		}

		// this code is the same as choice 1

		for (auto& th : myPrepThreads)
		{
			th.join();
		}

		// join the calculation thread back to the program

	}
	else if (choice == 2)
	{
		string key;
		string password;
		int threads_in_use;
		bool pCheck = false;
		int line_count = 0;
		int repeated = 0;
		cout << "Please input a key: ";
		cin >> key;
		cout << "How many threads would you like to use? ";
		cin >> threads_in_use;
		cout << "How many times would you like this program to be ran?";
		cin >> repeated;
		std::transform(key.begin(), key.end(), key.begin(), ::toupper);


		string temp_line;
		while (pCheck == false)
		{
			cout << "Please input your password from rockyou: ";
			cin >> password;
			std::ifstream rockyou("rockyou.txt");
			while (rockyou.peek() != EOF)
			{
				std::getline(rockyou, temp_line);
				if (temp_line == password)
				{
					pCheck = true;
				}
				++line_count;
			}
			rockyou.close();
		}

		string encrypted_password = encrypt(key, password);

		int line_incrementer = round(line_count / threads_in_use);


		std::vector<string> vOfData = fileToVector();

		for (int i = 0; i < repeated; ++i)
		{		
			int starting_line = 0;
			int ending_line = 0;
			global_counter = 0;
			auto* myCrackerThreads = new std::thread[threads_in_use];

			// up to this point, the code for choice 1 and choice 2 are identical


			// create a thread that starts recording the time it takes for the rest of the program to execute

			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); // when this thread is started, start the clock
			for (int counter = 0; counter < threads_in_use; ++counter)
			{

				ending_line += line_incrementer; 
				myCrackerThreads[counter] = std::thread(cracker, key, encrypted_password, vOfData, starting_line, ending_line, line_count);
				starting_line = ending_line;
			}

			for (int i = 0; i < threads_in_use; ++i)
			{
				myCrackerThreads[i].join();
			}
			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			int time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
			std::ofstream MyFile("8 thread.txt", std::ios_base::app);
			MyFile << time_taken << "ms" << endl;
			MyFile.close();
			// this code is the same as choice 1
		}
		
	}
	else
	{
		cout << "You picked an invalid option."; // if the user has not picked a valid option tell them that
		menu(); // return to the menu
	}
}
int main()
{
	menu(); // run the menu function
}


/*

set up a second thread function to read through the data and store it into a data structure(thread A)

Once thread A is complete, signal to the cracker threads and it tell it to start its process

no need for a mutex lock since there is no shared resource, only reading from the same thing


when the program starts it should send a signal to the second thread function that times how long it takes for all of the threads 
to finish, once its done, stops timing
run upwards of 100x

use semaphores
*/