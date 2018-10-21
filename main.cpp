#include "MorseTranslation.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	MorseTable hash;
	string hello;
	vector<int> code;
	cout << "Please enter a sentence in uppercase: " << endl;
	getline(cin, hello);

	int length = (int) hello.length();
	cout << "string is: " << hello << ", with length of: " << length << endl << endl;

	code = hash.stream(hello);

	for(int i = 0; i < length; i++)
	{
		cout << code.at(i) << '0';
	}
	cout << endl << endl;

	//hash.printTable();
	return 0;
}