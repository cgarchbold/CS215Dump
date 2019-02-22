//--------------------------------------------------------------------
// CS215-009 Lab 5
//--------------------------------------------------------------------
// Author: Cohen Archbold
// Date: 2/14/2019
// Description: This program asks the user to play a game and vaires between different games
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;

int main() {

	//initialize variables
	bool running = true;
	//used for sum game
	int start;
	int end;
	int sum;
	//used for box game
	int size;

	//start loop
	do {
		//give out options, ask for char input
		cout << "S - Sum Between" << endl;
		cout << "B - Print Box" << endl;
		cout << "X - Exit" << endl;
		cout << "Enter option:";
		char input;

		cin >> input;

		//use a switch to determine game selected
		switch (input) {
		//if S or s
		case 's': case 'S':
			//gain two numbers to sum between
			cout << "Enter starting number:";
			cin >> start;
			cout << "Enter ending number:";
			cin >> end;
			//set sum = 0
			sum = 0;
			//loop to sum the numbers inlcuding start and and in between
			for (int i = start; i <= end; i++)
				sum += i;
			//print out sum
			cout << "The Sum is: "<< sum << endl<<endl;
			break;

		//if b or B
		case 'b': case 'B':
			//ask for a size
			cout << "Enter Box Size:";
			cin >> size;
			//use nested loops to create a size*size box of astericks
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << "* ";
				}
				cout << endl;
			}
			cout << endl;
			break;
		//if x end the program
		case 'X': case 'x':
			cout << "Thanks For Playing!"<<endl<<endl;
			running = false;
			break;
		//if not a correct input inform user of the error
		default:
			cout << "Invalid option. Try agian!"<<endl<<endl;
			break;
		}


	} while (running);//running is only false after the user inputs X or x


	//finish
	system("PAUSE");
	return 0;



}