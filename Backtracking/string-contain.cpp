#include<iostream>
#include<string.h>
using namespace std;
bool contains(char large[], char small[])
{
    if(small[0] == '\0')
    {
        return true;
    }
    // if(a[0] != b[0])
    // {
    //     return false;
    // }
    if(large[0] == '\0' && small[0] != '\0')
    {
        return false;
    }
    if(large[1] != '\0' && small[1] != '\0')
    {
        if(large[0] == small[0])
        {
            return contains(large+1,small+1);
        }
        else{
            return contains(large+1,small);
        }
    }
}