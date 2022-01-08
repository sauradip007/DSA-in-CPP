#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
// int countdigs(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     int smallOutput = countdigs(n / 10);
//     return smallOutput + 1;
// }
int keypad(int input, string output[])
{
    if(input == 0)
    {
        output[0] = "";
        return 1;
    }

    // NUMBER is 234
    int smallNum = input % 10; //4
    int indexNum = input/ 10;  //23
    int smallOutput = keypad(indexNum, output); //gets all possible outputs for 23 in output string
    int comb = keypad(indexNum, output);
    // gets all possible combs of 4 and adds to output string
    int n = smallOutput*comb;
   
    for(int i = 0 ; i < smallOutput; i++)
     {
         
         output.substr(2) = output[i];

     }
     return n;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}