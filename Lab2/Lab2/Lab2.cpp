//--------------------------------------------------------------------
// CS215-009 LAB 2 
//--------------------------------------------------------------------
// Author: Cohen Archbold
// Date: 1/25/2019
// Description: This prgram uses if else statements to sort numbers and ask user questions
//--------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main() {

	//initialize input variables
	int input_1;
	int input_2;
	int input_3;

	//intialize sorting variables
	int first;
	int second;
	int third;

	//get user input for 3 numbers
	cout << "Enter a number 1: " ;
	cin >> input_1;

	cout << "Enter a number 2: " ;
	cin >> input_2;

	cout << "Enter a number 3: " ;
	cin >> input_3;

	
	//sort the numbers with nested loops
	if (input_1 <= input_2&&input_1 <= input_3) {
		first = input_1;
		if (input_2 <= input_3) {
			second = input_2;
			third = input_3;
		}
		else {
			second = input_3;
			third = input_2;
		}
	}

	if (input_2 <= input_1&&input_2 <= input_3) {
		first = input_2;
		if (input_1 <= input_3) {
			second = input_1;
			third = input_3;
		}
		else {
			second = input_3;
			third = input_1;
		}
	}

	if (input_3 <= input_2&&input_3 <= input_1) {
		first = input_3;
		if (input_2 <= input_1) {
			second = input_2;
			third = input_1;
		}
		else {
			second = input_1;
			third = input_2;
		}
	}

	//print out sorted list
	cout << "Sorted they are " << first << " " << second << " " << third << endl <<endl;


	//declare variables for pepper section
	string pepper_input;
	int scoville;

	//prompt user with choices
	cout << "A. Aleppo Pepper" << endl;
	cout << "B. Banana Pepper" << endl;
	cout << "C. Cayenne Pepper" << endl;
	cout << "D. Dragons Breath" << endl;
	cout << "Enter a letter to choose a pepper: " ;

	//get input for pepper letter
	cin >> pepper_input;

	//check which type of pepper, assign scoville value
	// if no scoville assign 0
	if (pepper_input == "A" || pepper_input == "a")
		scoville = 30000;
	else if (pepper_input == "B" || pepper_input == "b")
		scoville = 1000;
	else if (pepper_input == "C" || pepper_input == "c")
		scoville = 40000;
	else if (pepper_input == "D" || pepper_input == "d")
		scoville = 2480000;
	else
		scoville = 0;

	
	// if incorrewct input ( scoville=0) print error
	if (scoville == 0)
		cout << "That Pepper is not on the list :(" << endl;
	else
		//print out scoville units for correct pepper
		cout << "That's " << scoville << " Scovilles of heat!"<< endl;


	system("PAUSE");
	return 0;
}
