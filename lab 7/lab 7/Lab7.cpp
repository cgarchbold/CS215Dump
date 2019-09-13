//--------------------------------------------------------------------
// CS215-009 Lab 7
//--------------------------------------------------------------------
// Author: Cohen Archbold
// Date: 3/20/2019
// Description: This program calls created functions
//--------------------------------------------------------------------



#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;

const int MAX_FRAC = 10;




//Declare structure for a fraction
struct fraction {
	int num;
	int den;
	double decimal;
};

//--------------------------------------
//             askFraction
//--------------------------------------
fraction askFraction() {

	//make new fration ask for values
	fraction newFrac;
		cout << "Enter Numerator  :";
	cin >> newFrac.num;
	newFrac.den = 0;
	//denominator cannot be 0
	while (newFrac.den == 0) {
		cout << "Enter Denominator:";
		cin >> newFrac.den;
	}
	//assume decimal is 0
	newFrac.decimal = 0.0;
	return newFrac;

}// askFraction()


 //--------------------------------------
 //              calcDecimal
 //--------------------------------------
void calcDecimal(fraction &frac) {
	//dont divide by 0
	if (frac.den == 0) {
		frac.decimal = 0.0;
	}
	else
		frac.decimal = ((double)frac.num)/(double)frac.den; //calculate decimal, cast as double

}// calcDecimal()

 //--------------------------------------
 //              printFraction
 //--------------------------------------
void printFraction(fraction frac) {

	//print fraction in correct format
	cout << frac.num << " / " << frac.den << " (" << frac.decimal << ")";

}// printFraction()

 //--------------------------------------
 //              askFractionList
 //--------------------------------------
void askFractionList(fraction frac[]) {
	int numberFractions = 0;
	//get number between 1 and maxfrac
	while (numberFractions < 1 || numberFractions>MAX_FRAC) {
		cout << "Enter Number of Fractions:";
		cin >> numberFractions;

		if (numberFractions < 1 || numberFractions>MAX_FRAC) {
			cout << "Enter a number between 1 and 10" << endl;
		}
	}

	//populate list
	for (int i = 0; i < numberFractions; i++) {
		cout << "For Fraction " << i+1 << " :"<< endl;
		fraction newfrac = askFraction();
		calcDecimal(newfrac); //calculate the decimal value
		frac[i] = newfrac;
	}
	

}// askFractionList

 //--------------------------------------
 //              printFractionList
 //--------------------------------------
void printFractionList(fraction frac[]) {
	//print a list
	for (int i = 0; i < MAX_FRAC; i++) {
		if (frac[i].num != 0) {
			printFraction(frac[i]);
			cout << endl;
		}
	}

}// printFractionList()

 //--------------------------------------
 //              findMaxFraction
 //--------------------------------------
int findMaxFraction(fraction frac[]) {
	if (frac[0].num== 0) {
		return -1;
	}
	double max = 0.0;

	for (int i = 0; i < MAX_FRAC; i++) {
		if (frac[i].num != 0) {
			if (frac[i].decimal > max)
				max = frac[i].decimal;
		}
	}

	for (int i = 0; i < MAX_FRAC; i++) {
		if (frac[i].num != 0) {
			if (frac[i].decimal == max)
				return i;
		}
	}

}// findMaxFraction()

int main() {

	cout << fixed << setprecision(2);

	fraction frac[MAX_FRAC] = { 0 };
	askFractionList(frac);
	printFractionList(frac);
	cout << "The highest value fraction is: ";
	int x = findMaxFraction(frac);
	printFraction(frac[x]);
	cout << endl;


	system("PAUSE");
	return 0;
}
