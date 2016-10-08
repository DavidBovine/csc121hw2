#include <iostream>
#include <string>
#include <climits>
#include "inNum.h"
using namespace std;

double readDouble(string prompt)
{
	double rv=0.0;
	bool done=false;
	while (done == false){
		cout<< prompt;
		cin>>rv;
		if (cin.fail()!=0){
			cerr<<"Oops, cannot read data\n";
			cin.clear();
			cin.ignore(INT_MAX,'\n');
		}
		else{
			done=true;
		}
	}
	return rv;
}


double readDouble(string prompt, double minVal)
{
	double rv=0.0;
	bool done=false;
	while (done == false){
		rv=readDouble (prompt);
		if (rv<minVal){
			cerr<<"Alert! Value must be >= "<<minVal<<endl;
		}
		else{
			done=true;
		}
	}
	return rv;
}

double readDouble(string prompt, double minVal, double maxVal)
{
	double rv=0.0;
	bool done=false;
	while (done == false){
		rv=readDouble ( prompt, minVal);
		if (rv>maxVal){
			cerr<<"Alert! Value must be <= "<<maxVal<<endl;
		}
		else{
			done=true;
		}
	}
	return rv;
}

int readInt(string prompt)
{
	int rv=0.0;
	bool done=false;
	while (done == false){
		cout<< prompt;
		cin>>rv;
		if (cin.fail()!=0){
			cerr<<"Oops, cannot read data\n";
			cin.clear();
			cin.ignore(INT_MAX,'\n');
		}
		else{
			done=true;
		}
	}
	return rv;
}


int readInt(string prompt, int minVal)
{
	int rv=0.0;
	bool done=false;
	while (done == false){
		rv=readInt (prompt);
		if (rv<minVal){
			cerr<<"Alert! Value must be >= "<<minVal<<endl;
		}
		else{
			done=true;
		}
	}
	return rv;
}

int readInt(string prompt, int minVal, int maxVal)
{
	int rv=0.0;
	bool done=false;
	while (done == false){
		rv=readInt ( prompt, minVal);
		if (rv>maxVal){
			cerr<<"Alert! Value must be <= "<<maxVal<<endl;
		}
		else{
			done=true;
		}
	}
	return rv;
}
