#include <iostream>
#include <time.h>
#include "../../src/NBL.h"

#define DEBUG 1

using namespace std;
using namespace NobelLib;

int numFails = 0;
int numTests = 0;

void checkup(char* checkname, bool expression)
{
    numTests++;
    if(expression)
        cout << checkname << " test: [OK]\n";
    else
    {
        cout << checkname << " test: [FAILS]\n";
        numFails++;
    }
}

void result()
{
    cout << "Number of test Passed: " << numTests - numFails << endl;
    cout << "Number of test Failed: " << numFails << endl;
    cout << "Number of test Executed: " << numTests << endl;
    if(numFails == 0)
        cout << "All seems OK... but you can check https://github.com/Nobel3D/Nobel-Library to help me, it would be great! :D";
}

int main()
{
    #if DEBUG == 1
    Array<int> numbers(10);
    for(int i = 0; i < 10 ; i++)
        numbers[i] = i;
    checkup("Array allocation", numbers[0] == 0 && numbers[5] == 5 && numbers[9] == 9);

    numbers.Expand(12); numbers[10] = 10; numbers[11] = 11;
    checkup("Array adding", numbers[10] == 10 && numbers[11] == 11);

    numbers[1] = 99;
    checkup("Array replace", numbers[1] == 99);

    numbers.Clear();
    checkup("Array cleaning", numbers[2] != 2);

    int* othernumber = new int[10];
    for(int i = 0; i < 10 ; i++)
        othernumber[i] = i + 10;
    numbers.Copy(othernumber);
    checkup("Array copying", numbers[3] == 13);

    NString hello = "Hello";
    checkup("NString allocation", hello=="Hello");

    hello += " world";
    checkup("NString adding", hello=="Hello world");

    cout << hello.Replace("world", "guys") << endl;

    checkup("NString replace", hello.Replace("world", "guys") == "Hello guys");

    checkup("NString find", hello.Find("wor"));

    List<NString>* strList = new List<NString>; hello.Split(" ", strList);
    Array<NString>* space = strList->toArray();
    checkup("NString split", (*space)[0] == "Hello" && (*space)[1] == "world");
    cout << (*space)[0] << " " << (*space)[1] << endl;

    result();
    return 0;
    #else // DEBUG
    Array<NString> array(10);
    for(int i = 10; i < 10; i++)
    {
        array[i] = "ciao kek";
        cout << array[i] << endl;
    }

    return 0;
    #endif // DEBUG
}
