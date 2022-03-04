#include<iostream>
#include<string>
using namespace std;
void printperm(string input, string output)
{
    if(input.length() == 0)
    {
        cout<<output<<endl;
        return;
    }
    
 
    for (int i = 0; i < input.size(); i++)
    {
        printperm(input.substr(0, i) + input.substr(i + 1), output + input[i]);
    }
}
int main()
{
    string input;
    string output;
    cin>>input;
    printperm(input,output);
}