#include<iostream>
using namespace std;
void print_subs(string input , string output)
{
    if(input.length()== 0)
    {
        cout<<output<<endl;
        return;
    }
    print_subs(input.substr(1), output);//calling for all elements other than the first
    print_subs(input.substr(1), output+input[0]);//the second case where the first element is to be included
}
int main()
{
    string input = "ab";
    string output;
    print_subs(input,output);
}