#include<iostream>
#include<cstring>
using namespace std;
void print(string input, string output[])
{
    if(input.length()== 0)
    {
        cout<<output<<endl;
        return;
    }
    print(input.substr(1), output);
    // taking abc eg , bc is taken ,2 possibilities "" and "bc"
    print(input.substr(1),output+input[0]);
    // considers a combination as well "bc", "a"
}
int main()
{
    string input;
    cin>>input;
    string output = "";
    print(input,output);
 

}