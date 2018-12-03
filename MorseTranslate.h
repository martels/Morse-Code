#include <iostream>
#include <string>

using namespace std;

class table
{
    public:
        table();
        string _Text_2_Morse(char* msg, int length);
    private:
        char alphabet[37];
        string morse[37];
};


table::table()
{
    char a[37] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ' '};
    string m[37] = {"12", "2111", "2121", "211", "1", "1121", "221", "1111", "11", "1222", "212", "1211", "22", "21", "222", "1221", "2212", "121", "111", "2", "112", "1112", "122", "2112", "2122", "2211", "1222", "11222", "11122", "11112", "11111", "21111", "22111", "22211", "22221", "22222", "00"};
    for(int i = 0; i < 37; i++)
	{
        alphabet[i] = a[i];
        morse[i] = m[i];
	}
}

string table::_Text_2_Morse(string msg)
{
    length = sizeof(msg);
    string array[length];
    for(int i = 0; i < length; i++)
    {
        for(int k = 0; k < 37; k++)
        {
            if(msg[i] == alphabet[k])
            {
                array[i] = morse[k];
            }
        }
    }

    return array;
}

