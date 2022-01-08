#include<iostream>
#include "stacks_template_LL.h"
using namespace std;
#include<stack>
bool checkparent(string e)
{
    stack<char>s;
     int i = 0;
     while(e[i] != '\0')
     {
         if(e[i] == '(' || e[i] == '{' || e[i] == '[')
         {
             s.push(i);

         }
         else if(e[i] == ')' || e[i] == '}' || e[i] == ']')
         {
             
             s.pop();
         }
         i++;
         
     }
     if(s.empty())
     {
         return true;
     }
    return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<checkparent(s)<<endl;
}