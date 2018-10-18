#include "stringconvert.h"
#include "MorseTranslation.h"
#include <cstring>
#include <cstdlib>

using namespace std;


string InputDriver::getMsg()
{
	string in;
	cout << endl << "Please Input the message as one line: " << endl;
	getline(cin, in);
	return in;
}

int InputDriver::stream(string msg)
{
	MorseHash hash;
	int length = 0;
	length = (int) msg.length();
	char *temp = new char[msg.length()+1];
	strcpy(temp, msg.c_str());
	int totalmessage = 0;
	for(int i = 0; i <= length; i++)
	{
		totalmessage = totalmessage + hash.hashToMorse(temp[i]);
	}
	return totalmessage;
}