#if (0)

#define TIME_BASE 1500000

#include <string>
#include <vector>
#include "GPIOclass.h"

using namespace std;

int channel_clear = 0;
GPIOClass* gpio;


int morse_init(string& pin);
void morse_reset(string& pin);
void morse_end();

vector<string> morse_bitstream(vector<string>& morse);
void morse_write(vector<string>& msg);



#endif


MorseDriver.o: MorseDriver.cpp
	g++ -Wall -c MorseDriver.cpp