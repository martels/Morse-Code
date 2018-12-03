#include <iostream>
#include "MorseTranslate.h"

using namespace std;

int main()
{
    table testmessage;

    string msg = "hello";
    string message;

    message = testmessage._Text_2_Morse(msg);

    cout << endl << msg << endl << message << endl;
}