#ifndef MORSE_TRANSLATION_H
#define MORSE_TRANSLATION_H


#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class MorseElement
{
private:
	char alpha;
	int code;
public:
	char getAlpha() const {return alpha;};
	int getCode() const {return code;};
	void setAlpha(char a) {alpha = a;};
	void setCode(int c) {code = c;}; 
};


class MorseHash
{
private:
	MorseElement table[34];
public:
	MorseHash();
	int hashToMorse(char key);
	char hashToAlpha(int msg);
//char charCertify(char key);
};

#endif