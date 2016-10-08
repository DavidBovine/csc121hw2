/* This program predicts the trajectory of Yikes the clown as he
 * is shot out of a cannon. The user simply inputs the velocity and 
 * angle of the cannon. The program will return a table with your
 * positions through time and space.					*/



#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

double deg2rad(double deg);
double findRangeT(double v, double rad);
double findTimeT(double rangeT, double v, double arad);
double Tstep(double TimeTotal);
double TrajTable(int n);
double findHeight(double tn, double v, double arad);
double findRange(double tn, double v, double arad);

const double g=9.81965;
double vel=0.0, RT=0.0, TimeT=0.0, TimeS=0.0, TimeN=0.0, adeg=0.0, arad=0.0;
int inc=0;
bool done=false, fin=false;

int main()
{
	
	char cloop='y';
	
	cout<< "Welcome Yikes...\nI will calculate your trajectory today.\n";
	
while (fin==false)
{
	while (done==false)
	{
		cout<<"What is the velocity? [m/s]: ";
		cin>>vel;
		if (cin.fail() !=0){
			cout<<"Could not read data\n";
			cin.clear();
			cin.ignore(INT_MAX,'\n');
		}
		else{
			if(vel>=0.0){
				cout<<endl;
				done=true;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
			}
			else{
				cout<<"Your speed can't be negative\n";
			}
		}
	}
	done=false;
	while (done==false)
	{
		cout<<"What is the angle of the cannon? [deg]: ";
		cin>>adeg;
		if (cin.fail() !=0){
			cout<<"Could not read data\n";
			cin.clear();
			cin.ignore(INT_MAX,'\n');
		}
		else
		{
			if(adeg>=0.0 && adeg<=90){
				cout<<endl;
				done=true;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
			}
			else{
				cout<<"Your angle must be between 0 and 90\n";
			}
		}
	}
	done=false;
	
	cout.precision (5);		//for table formmating
	cout.setf (ios::fixed,ios::floatfield);
	//next is all the math
	arad=deg2rad(adeg);
	RT=findRangeT (vel,arad);
	TimeT=findTimeT(RT,vel,arad);
	TimeS=Tstep(TimeT);
	TrajTable(inc);
	TimeN=0.0;
	//main while loop
	while (done==false)
	{
		cout<<"Would you like to splat again? [y/n]: ";
		cin>>cloop;
		if (cin.fail() !=0){
			cout<<"could not read input\n";
			cin.clear();
			cin.ignore(INT_MAX,'\n');
		}
		else{
			//done=true;
			if(tolower(cloop) == 'y')
			{
				cout<< "Ok then \n\n" ;
				fin=false;
				done=true;
				cin.ignore(INT_MAX,'\n');
			}
			else if(tolower(cloop) == 'n')
			{
				cout<< "Goodbye\n\n";
				fin=true;
				break;
			}
			else if ( tolower(cloop) != 'y' && tolower(cloop) != 'n')
			{
				cout<< "What was that fat fingers? It's y or n\n";
				cin.ignore(INT_MAX,'\n');
			}
		}
	}
	done=false;
}
	return (0);
}

/*Functions called in main.*/

double deg2rad(double deg)
{
	return (deg*(M_PI/180));
}

double findRangeT(double v, double rad)
{
	double d =0.0;
	
	d= pow(v,2)/g * sin(2*(rad));
	
	cout<<"You will travel "<<d<<" meters before splattering the ground."<<endl;
	
	return d;
}

double findTimeT(double rangeT, double v, double rad)
{
	return (rangeT/(v * cos(rad)));
}

double Tstep(double TimeTotal)
{
	return (TimeTotal/20);
}

double TrajTable(int n)
{
	cout<< "The total hang time is "<< TimeT<<endl;
	cout<< "Time		Distance		Height"<<endl;
	while (n<=20)
	{
		cout<<TimeN<<"s	";
		findRange(TimeN,vel,arad);
		cout<<"m		";
		findHeight(TimeN,vel,arad);
		cout<< "m\n";
		TimeN=TimeN+TimeS;
		n++;
	}
	return 0;
}

double findHeight(double tn, double v, double arad)
{
	cout<<(v*sin(arad)) * tn - .5 * g * pow(tn,2);
	return 0;
}

double findRange(double tn, double v, double arad)
{
	cout<<v*cos(arad)*tn;
}