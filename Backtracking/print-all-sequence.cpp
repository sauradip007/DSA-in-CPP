#include<iostream>
#include<string>
using namespace std;
char ctc(char i)
{
    return 'a' - i + 1;
}
char cti(int a)
{
    return a - '0';
}
void printHelper(string input, string output)
{
    if(input.length() == 0)
    {
        cout<<output<<endl;
        return;
    }
    if(input[0] == '0') //no char corresponds to 0
    {
        printHelper(input.substr(1),output);
    }else{
        char ch1 = ctc(cti(input[0]));
        printHelper(input.substr(1),output+ch1);
    }
    if(input.length() > 1)//taking 2 at a time
    {
        char ch2 = ctc(cti(input[0])*10 + cti(input[1]));
        if (10 <= cti(input[0]) * 10 + cti(input[1]) && cti(input[0]) * 10 + cti(input[1])<=26){
            printHelper(input.substr(2),output+ch2);
        }
    }
}