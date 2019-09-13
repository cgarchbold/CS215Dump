#include <iostream>
#include "contact.h"
#include "contactList.h"


contactList::contactList() { listName = "none"; numberContacts = 0; }

string contactList::getName() { return listName; }
void contactList::setName(string n) { listName = n; }

int contactList::getNumContacts() { return numberContacts; }

void contactList::addContact(contact c) {

	if (numberContacts != 5) {
		list[numberContacts] = c;
		numberContacts = numberContacts + 1;
	}
	else {
		cout << "contactList::addContact(): max contacts exceeded!"<<endl;
		cout << c.getName() << "not added!";
	}

}

int contactList::searchByName(string n) {

	for (int i = 0; i < numberContacts; i++) {
		if (list[i].getName() == n) {
			return i;
		}
	}
	return -1;
}

