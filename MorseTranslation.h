#ifndef MORSE_TRANSLATION_H
#define MORSE_TRANSLATION_H


#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class MorseElement
{
public:
	char alpha;
	int code;
	char getAlpha() const {return alpha;};
	int getCode() const {return code;};
//	void setAlpha(char a) {alpha = a;};
//	void setCode(int c) {code = c;}; 
	friend ostream& operator<< (ostream& ostr, const MorseElement& rhs);
};



class MorseTable
{
private:
	MorseElement table[37];
public:
	MorseTable();
	int hashToMorse(char key);
	char hashToAlpha(int msg);
	void printTable();
	vector<int> stream(string msg);
//char charCertify(char key);
};


#endif