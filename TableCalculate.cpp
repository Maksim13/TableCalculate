#include "stdafx.h"
#include "HEAD.h"
#include "offer.h"
int main()
{
	vector <Table *> v;
	fstream f1("data1.txt",ios::in);
	try
	{
		if(!f1)
		{
			Range *ex = new Range("file error!");
			throw ex;
		}
	}
	catch(Range *ex){ex->sendMessage();}
	vector <Table *>::iterator i;
	SquareTable *s = new SquareTable;
	CircleTable *c = new CircleTable;
	try 
	{
		while(!f1.eof())
		{
			f1 >> *s;
			v.push_back(new SquareTable(*s));
			f1 >> *c;
			v.push_back(new CircleTable(*c));
		}
	}
	catch(Range *ex){ex->sendMessage();}
	for(i = v.begin();i != v.end();i++)
		cout << (**i) << endl;
	fstream f2("data2.txt",ios::out);
	try
	{
		if(!f2)
		{
			Range *ex = new Range("file error!");
			throw ex;
		}
	}
	catch(Range *ex){ex->sendMessage();}
	for(i = v.begin();i != v.end();i++)
		f2 << (**i) << endl;
	Table::displayCount();
	cout << "Total price of tables: " << TotalPrice(v) << "$" << endl;
	for(i = v.begin();i != v.end();i++)
		delete (*i);
	Table::displayCount();

	cout << endl
		 << "Make offer?" << endl
		 << "1. Yes." << endl
		 << "2. No." << endl;
	int choose;
	cin >> choose;
	Offer *o=new Offer();
	getchar();
	
	switch (choose) {

		case 1: o->getValues(); o->toFile(f2); break;
		case 2: break;
		default: cout << "Invalid answer." << endl; break;

	}

	delete o;

	return 0;
}