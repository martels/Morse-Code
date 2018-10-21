#include "MorseTranslation.h"

using namespace std;

MorseTable::MorseTable()
{
	char alphabet[37] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' '};
	int code[37] = {12, 2111, 2121, 211, 1, 1121, 221, 1111, 11, 1222, 212, 1211, 22, 21, 222, 1221, 2212, 121, 111, 2, 112, 1112, 122, 2112, 2122, 2211, 1222, 11222, 11122, 11112, 11111, 21111, 22111, 22211, 22221, 22222, 00};
	MorseElement temp;
	for(int i = 0; i < 37; i++)
	{
		temp.alpha = alphabet[i];
		temp.code = code[i];
		this->table[i] = temp;
	}
}

int MorseTable::hashToMorse(char key)
{
//	key = charCertify(key);
	for(int i = 0; i < 37; i++)
	{
		if(table[i].alpha == key)
		{
			return table[i].code;
		}
	}
	return -1;
}

char MorseTable::hashToAlpha(int msg)
{
	for(int i = 0; i < 37; i++)
	{
		if(table[i].code == msg)
		{
			return table[i].alpha;
		}
	}
	return -1;
}

void MorseTable::printTable()
{
	for(int i = 0; i < 37 ; i++)
	{
		cout << table[i] << endl;
	}
	return;
}

ostream& operator<< (ostream& ostr, const MorseElement& rhs)
{
	ostr << "AlphaNumeric: " << rhs.alpha << ", Numeric reprentation of Morse code: " << rhs.code;
	return ostr;
}

vector<int> MorseTable::stream(string msg)
{
	vector<int> code;
	int length = (int) msg.length();

	for(int i = 0; i < length; i++)
	{
		code.push_back(this->hashToMorse(msg[i]));
	}
	return code;
}

// char MorseTable::charCertify(char key)
// {
// 	char lowercase[37] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' '};
// 	for(int i = 0; i < 37; i++)
// 	{
// 		if(lowercase[i] == key)
// 			key = table[i].getAlpha();
// 	}
// 	return key;
// }
