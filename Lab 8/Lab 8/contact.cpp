#include "contact.h"
#include <iomanip>
#include <iostream>

contact::contact() { name = "EMPTY"; phone = ""; }

string contact::getName(){return name;}string contact::getPhone() { return phone; }void contact::setPhone(string s) { phone = s; }void contact::setName(string n) { name = n; }void contact::print() {	cout << setw(12) << name <<" "<< phone;}