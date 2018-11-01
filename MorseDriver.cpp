#include "MorseDriver.h"
#include "GPIOclass.h"
#include <vector>
#include <string>


int morse_init(string& pin)
{
	gpio = new GPIOclass(pin);	//create new GPIO object to be attached to GPIO
	if(gpio->export_gpio() == -1)
		return -1; //export GPIO
	gpio->setdir_gpio("out"); // GPIO17 set to input
	channel_clear = 1;
	return 1;
}

void morse_reset(string& pin)
{	
	channel_clear = 0;
	gpio->unexport_gpio();
	gpio = new GPIOclass(pin);	//create new GPIO object to be attached to GPIO
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


vector<string> morse_bitstream(vector<string>& morse)
{
	vector<string> stream;
	string temp;
	int length;
	while(morse)
	{
		temp = morse.pop_front();
		length = temp.length();
		for(int i = 0; i < length; i++)
		{
			if(temp[i] == 1)
			{
				stream.push_back("1");
				stream.push_back("0");
			}
			else if(temp[i] == 2)
			{
				stream.push_back("1");
				stream.push_back("1");
				stream.push_back("0");
			}
			else if(temp[i] == 0)
			{
				stream.push_back("0");
			}
			else
			{
				cerr << "error in bitstream \n";
				exit(1);
			}
		}
		stream.push_back("0");
	}
	return stream;
}

void morse_write(vector<string>& msg)
{
	vector<string> bits = morse_bitstream(msg);
	string temp;
	while(bits)
	{
		if(channel_clear = 1)
		{
			channel_clear = 0;
			temp = bits.pop_front();
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
