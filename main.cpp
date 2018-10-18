//#include "MorseTranslation.h"
#include "stringconvert.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	InputDriver input;
	string msg;
	int send;
	msg = input.getMsg();
	cout << endl << "point1" << endl;
	send = input.stream(msg);
	cout << endl << "point2" << endl;


	cout << endl << "the outstream is: " << endl << send << endl << endl;



	return 0;
}