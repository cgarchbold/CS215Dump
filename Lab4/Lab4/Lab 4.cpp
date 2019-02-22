//--------------------------------------------------------------------
// CS215-009 Lab 4
//--------------------------------------------------------------------
// Author: Cohen Archbold
// Date: 2/14/2019
// Description: This program reads a data file and exports a properly formatted one
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;

int main() {

	//instantiate viariables
	string Day;
	int numVals;
	int var;
	int max;
	int min;


	//attempt to open output file, shoudl create if does not exist
	ofstream fout;
	fout.open("tempsout.txt");

	//give error message if file does not open
	if (fout.fail()) {
		cout << "Error opening out file.";
		system("PAUSE");
		return 0;
	}

	//create first lines of output file
	fout << "DATE         HIGH   LOW" << endl;
	fout << "------------ ----  ----" << endl;   



	//open input file
	ifstream f;
	f.open("tempsin.txt");
	if (!f.fail()) {

		//loop until "ENDOFDATA" forces out of loop with return 0
		while (true) {

			//excrate the date and number of datapoints
			f >> Day >> numVals;

			//reset max and min to "impossible values"
			max = 0;
			min = 100000;

			//if endofdata reached return out of the loop
			if (Day == "ENDOFDATA") {                   
				f.close();
				fout.close();
				return 0;
			}

			//loop and extract each data value , track max
			for (int i = 0; i < numVals; i++) {
				//get val
				f >> var;

				//check if value is lower or larger than the min and max respectivley
				if (var > max)
					max = var;
				if (var < min)
					min = var;
			}

			//output data to tempsout.txt properly formatted
			fout << Day << setw(6) << max << setw(6) << min << endl;

		}

		//close both files
		f.close();
		fout.close();

	}

	//if input file does fails give error
	else {
		cout << "Error opening file.";
		system("PAUSE");
		return 0;
	}

}

