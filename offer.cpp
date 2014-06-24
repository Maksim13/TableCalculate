#include "stdafx.h"
#include "offer.h"

using namespace std;

Offer::Offer() {}
void Offer::getValues() {

	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your number: ";
	getline(cin, number);

}

void Offer::toFile(ostream & os) {

	os << name << endl;
	os << number << endl;

	cout << endl << "Offer maked succesful!" << endl;

}