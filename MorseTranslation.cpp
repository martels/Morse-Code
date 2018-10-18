#include "MorseTranslation.h"

using namespace std;

MorseHash::MorseHash()
{
	char alphabet[37] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' '};
	int code[37] = {120, 21110, 21210, 2110, 10, 11210, 2210, 11110, 110, 12220, 2120, 12110, 220, 210, 2220, 12210, 22120, 1210, 1110, 20, 1120, 11120, 1220, 21120, 21220, 22110, 12220, 112220, 111220, 111120, 111110, 211110, 221110, 222110, 222210, 22222, 0};
	MorseElement temp;
	for(int i = 0; i < 37; i++)
	{
		temp.setAlpha(alphabet[i]);
		temp.setCode(code[i]);
		this->table[i] = temp;
	}
}

int MorseHash::hashToMorse(char key)
{
//	key = charCertify(key);
	for(int i = 0; i < 37; i++)
	{
		if(table[i].getAlpha() == key)
		{
			return table[i].getCode();
		}
	}
	return -1;
}

char MorseHash::hashToAlpha(int msg)
{
	for(int i = 0; i < 37; i++)
	{
		if(table[i].getCode() == msg)
		{
			return table[i].getAlpha();
		}
	}
	return -1;
}

// char MorseHash::charCertify(char key)
// {
// 	char lowercase[37] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' '};
// 	for(int i = 0; i < 37; i++)
// 	{
// 		if(lowercase[i] == key)
// 			key = table[i].getAlpha();
// 	}
// 	return key;
// }
