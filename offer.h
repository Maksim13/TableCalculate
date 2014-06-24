#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Offer {

private:
	string name;
	string number;

public:
	Offer();
	void getValues();
	void toFile(ostream & os);

};