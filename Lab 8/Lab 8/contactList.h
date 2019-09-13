
#include <iostream>
#include "contact.h"
using namespace std;

const int MAX_CONTACTS = 5;

class contactList {
	
	contact list[MAX_CONTACTS];
	string listName;
	int numberContacts;

public:
	void setName(string n);
	string getName();

	int getNumContacts();

	void addContact(contact c);
	
	int searchByName(string n);

	contact getContact(int i);

	void print();
	

};

