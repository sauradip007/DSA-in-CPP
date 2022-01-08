#include<iostream>
#include<cstring>
using namespace std;
bool checkAB(char input[])
{
    if(strlen(input) <= 1)
    {
        return false;
    }
    if(input[0] == 'a')
    {
        checkAB(input+1);

    }
}