//--------------------------------------------------------------------
// CS215-009 LAB 6
//--------------------------------------------------------------------
// Author: Cohen Archbold
// Date: 2/1/2019
// Description: The purpose of this program is to read file data and store it in an array for output
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;


int main() {

	//set decimale precision to 2
	cout << fixed << setprecision(2);

	//intialize variables
	string stockName;
	string Date;
	string filename;
    const int  NUM_HOURS = 10; //constant array size
	double change;
	double high=0;
	double low=10000;
	double sum4Avg=0;
	double average;
	double median;

	//ask for filename
	cout << "Please enter stock data filename: ";
	cin >> filename;

	//check if exists, give error if not
	ifstream f;
	f.open(filename);
	if (f.fail()) {
		cout << "Unable to Read File : " << filename << endl;
		system("PAUSE");
		return 0;
	}
	

	//get name and date at the top of file
	f >> stockName >> Date;
	
	//create array for prices of stock hourly
	double prices[NUM_HOURS];

	//use a loop to fill array, check for max and minimums
	for (int i = 0;i < NUM_HOURS;i++) {
		f >> prices[i];
		//finding highest and lowest values
		if (prices[i] < low)
			low = prices[i];
		if (prices[i] > high)
			high = prices[i];
		//add for total of all values to be used to calculate avg later
		sum4Avg += prices[i];
	}
	//find change from the entire day
	change = prices[NUM_HOURS-1] - prices[0];

	//USE BUBBLE SORT TO SORT THE ARRAY
	for (int i = 0;i < NUM_HOURS-1;i++) {
		for (int j = i + 1;j < NUM_HOURS;j++) {
			if (prices[i] < prices[j]) {
				double x = prices[i];
				prices[i] = prices[j];
				prices[j] = x;
			}
		}
	}

	//FIND THE MEDIAN OF THE SORTED ARRAY
	median = (prices[NUM_HOURS / 2] + prices[NUM_HOURS / 2 - 1]) / 2;


	//calculate the average of all the values
	average = sum4Avg / NUM_HOURS;

	//begin output
	cout << "STOCK: " << stockName << "  DATE: " << Date << endl;

	cout << "TIME         PRICE" << endl;
	cout << "-----        -------" << endl;

	int hour = 8;

	//loop to print
	for (int i = 0;i < NUM_HOURS;i++) {
		cout << setw(2) << hour<<":00       $" << setw(7) << prices[i] << endl;
		hour++;
		if (hour == 13)
			hour = 1;
	}



	//output calculated values
	cout <<endl << "CHANGE:     $" << setw(7) << change << endl;
	cout << "HIGH:       $" << setw(7) << high << endl;
	cout << "LOW:        $" << setw(7) << low << endl;
	cout << "AVERAGE:    $" << setw(7) << average << endl;
	cout << "MEDIAN:     $" << setw(7) << median << endl;
	
	
	
	system("PAUSE");
	return 0;


}