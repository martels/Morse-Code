#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <queue>
#include "MorseTranslation.h"
//#include "MorseDriver.h"
#include "GPIOclass.h"

using namespace std;

#define TIME_BASE 150000

int channel_clear = 0;
GPIOClass* gpio;


int morse_init(string pin);
int morse_reset(string pin);
void morse_end();

queue<string> morse_bitstream(queue<string> morse);
void morse_write(queue<string> msg);



int main()
{
	string pin = {"4"};
	MorseTable hash;
	string msg;
	queue<string> code, stream;

	cout << "Please enter a sentence in uppercase: " << endl;
	getline(cin, msg);

	int length = (int) msg.length();
	cout << "string is: " << msg << ", with length of: " << length << endl << endl;

	morse_init();


	code = hash.stream(msg);
	stream = morse_bitstream(code);



	// for(int i = 0; i < length; i++)
	// {
	// 	cout << code.at(i) << ' ';
	// }
	// cout << endl << endl;



	// for(uint i = 0; i < stream.size(); i++)
	// {
	// 	cout << stream.at(i) << ' ';
	// }
	// cout << endl << endl;



	morse_write(code);
	morse_end();



	//hash.printTable();
	return 0;
}





int morse_init(string& pin)
{
	gpio = new GPIOClass(pin);	//create new GPIO object to be attached to GPIO
	if(gpio->export_gpio() == -1)
		return -1; //export GPIO
	gpio->setdir_gpio("out"); // GPIO17 set to input
	channel_clear = 1;
	return 1;
}

int morse_reset(string& pin)
{	
	channel_clear = 0;
	gpio->unexport_gpio();
	gpio = new GPIOClass(pin);	//create new GPIO object to be attached to GPIO
	if(gpio->export_gpio() == -1) 
		return -1;//export GPIO
	gpio->setdir_gpio("out"); // GPIO17 set to input
	channel_clear = 1;
	return 1;
}

void morse_end()
{
	gpio->unexport_gpio();
}


queue<string> morse_bitstream(queue<string> morse)
{
	queue<string> stream;
	string temp;
	int length;
	while(morse.size())
	{
		temp = morse.front();
		morse.pop();
		length = temp.length();
		for(int i = 0; i < length; i++)
		{
			if(temp[i] == 1)
			{
				stream.push("1");
				stream.push("0");
			}
			else if(temp[i] == 2)
			{
				stream.push("1");
				stream.push("1");
				stream.push("0");
			}
			else if(temp[i] == 0)
			{
				stream.push("0");
			}
			else
			{
				cerr << "error in bitstream \n";
				exit(1);
			}
		}
		stream.push("0");
	}
	return stream;
}

void morse_write(queue<string> msg)
{
	queue<string> bits; 
	bits = morse_bitstream(msg);
	string temp;
	while(bits.size())
	{
		if(channel_clear == 1)
		{
			channel_clear = 0;
			temp = bits.front();
			bits.pop();
			if(temp == "1")
			{
				gpio->setval_gpio("1");
				usleep(TIME_BASE);
				channel_clear = 1;
			}
			else if(temp == "0")
			{
				gpio->setval_gpio("0");
				usleep(TIME_BASE);
				channel_clear = 1;
			}
			else
			{
				cerr << "error in write \n";
				exit(0);
			}
		}
	}
}
