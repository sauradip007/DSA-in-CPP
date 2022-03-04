#include<iostream>
#include<string>
using namespace std;
int ctoi(char a)
{
    return a -'0';
}
//converts character to number and makes the map
char itoc(int i)
{
    return 'a' + i - 1;
}
int getCodes(string input, string output[10000])
{
    if(input.length() == 0)
    {
        output[0] = "";
        return 1;
    }
    //initialising result 1
    string result1[10000];
    //initialising result 2
    string result2[10000];
    //taking '1123', first split as '1 | 123'

    //small calc for 1
    char r = itoc(ctoi(input[0]));
    //make first recursion call 
    int smallOutputsize1 = getCodes(input.substr(1),result1);
    for(int i = 0; i < smallOutputsize1; i++)
    {
        result1[i] += r;
    //appending result r
    }

    //check constraint for first 2 characters in string
    //  ctoi(input[0])*10 + ctoi(input[1])
    int l = ctoi(input[0])*10 + ctoi(input[1]);
    int smallOutputsize2 = 0;
    if(10 <= l && l <= 26 && input[1] !='\0')
    {
        //first 2 chars are in range
        char s = itoc(l);
        //Now we are taking 11 | 23
         smallOutputsize2 = getCodes(input.substr(2),result2);
        for(int i = 0; i < smallOutputsize2; i++)
        {
            result2[i] += s;
            // appending result s
        }

    }
    //The results will finally be stored in a final output string array
    
   
    for(int i = 0; i < smallOutputsize1; i++)
    {
        for(int j = 0; j < result1[i].size(); j++)
        {
            output[i][j] = result1[i][j];
        }
    }
    for(int i = 0 ; i < smallOutputsize2; i++)
    {
        for(int j = 0 ; j < result2[i].length(); j++)
        {
            output[i+smallOutputsize1][j] = result2[i][j];
        }
    }
    return smallOutputsize1 + smallOutputsize2;
}