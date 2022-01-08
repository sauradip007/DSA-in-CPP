#include<iostream>
using namespace std;
int subsequence(string input, string output[])
// returns size of output i.e. how much the output array is filled up
{
    if(input.empty()) //if input string is empty
    {
        output[0]= "";//empty string combination stored in output array
        return 1; //returns 1 combination only
    }
    string smallString = input.substr(1);//displays string after 1st index to call recursion on
    int smallOutput = subsequence(smallString,output);//all subsequences of "bc" stored in output if input is "abc" say
    // now we have to attach a to all of them
    for(int i = 0 ; i < smallOutput; i++)
    {
        output[i+ smallOutput] = input[0] + output[i];// 2 copies of array created
        // adds a to all the subsequences of bc and inputs it after the position of the array has been filled by all bc subsequences
    }
    return 2* smallOutput; 
    // since array size becomes double now we return double the no of permutations which is given by SmallOutput
}
int main()
{
    string input;
    cin>>input;
    string* output = new string[1000];
    int count = subsequence(input,output); //how many subsequences there
    for(int i  = 0; i < count ; i++)
    {
        cout<<output[i]<<" ";
    }cout<<endl;

}