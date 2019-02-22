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
using namespace std;




int main() {

	cout << "--- Cohen Archbold's Hot Dogs & Drinks --- "<< fixed << setprecision(2) << endl<< endl;

	int x = 1;
	string input;
	double subtotal = 0;

	while (x != 0) {
	
		cout << "H - Hot Dog    "  << setw(10) << "$2.50   ";
		cout << "D - Deluxe Hot Dog" << setw(10) << "$3.50   " << endl;

		cout << "S - Small Drink" << setw(10) << "$1.50   ";
		cout << "L - Large Drink   " << setw(10) << "$2.25   " << endl;

		cout << "F -  Finish Order        " << setw(10);
		cout << "X - Exit System" << setw(10) << endl;


		cout << "Enter Option ===> ";


		getline(cin, input);

		double tax;
		double total;
		double change;
		double cash_input;
	


		switch (input[0]) {

			case 'h': case 'H':
				subtotal += 2.50;
				cout << "Current Sub Total: $ "  << subtotal  << endl << endl;
				break;

			case 'd': case 'D':
				subtotal += 3.50;
				cout << "Current Sub Total: $ "  << subtotal  << endl << endl;
				break;

			case 's': case 'S':
				subtotal += 1.50;
				cout << "Current Sub Total: $ "  << subtotal  << endl << endl;
				break;

			case 'l': case 'L':
				subtotal += 2.25;
				cout << "Current Sub Total: $ "  << subtotal  << endl << endl;
				break;

			case 'f': case 'F':
				x = 0;
				tax = subtotal*0.06;
				cout << "Tax:   " <<setw(5)<<"$ " << tax << endl;
				total = subtotal + tax;
				cout << "Total: "<< setw(5) << "$ "  << total  << endl;
				
				cout << "Enter cash:";
				cin >> cash_input;

				change = cash_input - total ;
				cout << "Change:" << setw(5) << "$ " << change<<endl;

				subtotal = 0;

				break;

			case 'x': case 'X':
				x = 0;
				break;
		}

		



	}










	system("PAUSE");
	return 0;
}