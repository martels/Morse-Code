#ifndef STRING_CONVERT_H
#define STRING_CONVERT_H

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class InputDriver
{
public:
	string getMsg();
	int stream(string msg);
};

#endif