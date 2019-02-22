//--------------------------------------------------------------------
// CS215-009 LAB 3
//--------------------------------------------------------------------
// Author: Cohen Archbold
// Date: 2/1/2019
// Description: This program uses loops to run a virtual food stand
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

double highGal;
double medGal;
double lowGal;

double highPrice;
double medPrice;
double lowPrice;


int main() {
	
	cout <<fixed<< setprecision(2);

	ifstream f;
	f.open("pumpin.txt");
	if (!f.fail()) {
		f >> highGal >> medGal >> lowGal >> highPrice >> medPrice >> lowPrice;
		f.close();
	}	else {		cout << "Unable to Read File..."<<endl;		system("PAUSE");		return 0;	}

	cout << "Tank Readings: " << setw(8) << "Hi= " << highGal << setw(8)<< "Med= " << medGal << setw(8)<< "Low= " << lowGal<<endl;
	cout << "Today's PPG:    " << setw(8) << "Hi=$ " << highPrice << setw(8) << "Med=$ " << medPrice << setw(10) << "Low=$ " << lowPrice << endl;

	cout << "-------------------------------------------------------------------------" << endl;
	cout << "+                     WELCOME TO MY GAS STATION                         +" << endl;
	cout << "+                       Cohen Archbold, Owner                           +" << endl;
	cout << "-------------------------------------------------------------------------" << endl;

	string rewards_input;
	int x = 1;
	bool rewardMember;

	while (x != 0) {
		cout << "Are you a Rewards Customer? (Y/N):  ";
		cin >> rewards_input;

		if (rewards_input == "y" || rewards_input == "Y") {
			rewardMember = true;
			x = 0;
		}
		else if (rewards_input == "N" || rewards_input == "n") {
			rewardMember = false;
			x = 0;
		}
		else if (rewards_input == "shutdown") {
			cout << "Shutting Down....." << endl;			system("PAUSE");			return 0;
		}
		else {
			cout << "Please enter a Y or N" << endl;
		}

	}

	double discount;

	if (rewardMember) {
		int rewardsNumber;
		cout << "Enter customer rewards number:      ";
		cin >> rewardsNumber;
		discount = ((rewardsNumber % 10) + 1) ;
		discount = (double)discount / 100;
	}
	else
		discount = 0.00;

	cout <<"Price Per Gallon Discount:          $"<<discount<<endl<<endl;	

	cout << "Prices Per Gallon:" << endl;
	cout << "High Octane:    $ " << highPrice << endl;
	cout << "Medium Octane:  $ " << medPrice << endl;
	cout << "Low Octane:     $ " << lowPrice << endl;
	
	//octane choice 1==high, 2==med, 3==low
	int octane_choice = 0;
	string octane_input;

	while (octane_choice == 0) {
		cout << "Select Octane (H/M/L):  ";
		cin >> octane_input;

		if (octane_input == "H" || octane_input == "h") {
			octane_choice = 1;
		}
		else if (octane_input == "M" || octane_input == "m") {
			octane_choice = 2;
		}
		else if (octane_input == "L" || octane_input == "n") {
			octane_choice = 3;
		}
		else {
			cout << "Error. Please enter a H, M, or L!" << endl;
		}

	}






	system("PAUSE");
	return 0;
}