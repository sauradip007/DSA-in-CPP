#include<iostream>
#include<string>
using namespace std;
void printsub(string input, string output)
{
    if(input.length() == 0)
    {
        cout<<output<<endl;
        return;
    }
    //not including 0th char
    printsub(input.substr(1),output);
    //including 0th char
    printsub(input.substr(1),output+input[0]);

}

int main()
{
    string input;
    cin>>input;
    string output;
    printsub(input,output);
    
}