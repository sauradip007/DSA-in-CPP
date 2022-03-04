#include<iostream>
#include<string>
using namespace std;
int subsequence(string input, string output[]){
    //output array gets filled with strings
    //int func returns no. of strings being filled up in the array
    if(input.empty())
    {
        output[0] = " ";
        return 1; //1 slot in array filled
    }
    int smallOutput = subsequence(input.substr(1),output);
    for(int i = 0; i < smallOutput; i++)
    {
        output[i+smallOutput] = input[0] + output[i];
    }
    return 2*smallOutput;
}
int main()
{
    string input;
    cin>>input;
    string*output = new string[1000];
    int count = subsequence(input,output);
    for(int i = 0; i < count; i++)
    {
        cout<<output[i]<<" ";
    }
}