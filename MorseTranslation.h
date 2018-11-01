#ifndef MORSE_TRANSLATION_H
#define MORSE_TRANSLATION_H


#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MorseElement
{
public:
	char alpha;
	string code;
	char getAlpha() const {return alpha;};
	string getCode() const {return code;};
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
	string hashToMorse(char key);
	// char hashToAlpha(string msg);
	void printTable();
	queue<string> stream(string msg);
//char charCertify(char key);
};


#endif