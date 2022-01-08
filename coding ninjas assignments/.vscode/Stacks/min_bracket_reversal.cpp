#include <iostream>
#include<cstring>
using namespace std;
#include <stack>
bool checkparent(string e)
{
    stack<char> s;
    int i = 0;
    while (e[i] != '\0')
    {
        if (e[i] == '(' || e[i] == '{' || e[i] == '[')
        {
            s.push(i);
        }
        else if (e[i] == ')' || e[i] == '}' || e[i] == ']')
        {

            s.pop();
        }
        i++;
    }
    if (s.empty())
    {
        return true;
    }
    return false;
}
int bracketrev(string e)
{
    stack<char>s;
    char c = s.top();
    s.pop();
    int i = 0;
    int l = e.length();
    int count = 0;
    if (l % 2 != 0)
    {
        return -1;
    }
    while(e[i] != '\0')
    {
        if(e[i] == '{')
        {
            s.push(e[i]);
        }
        

        if(e[i] == '}')
        {
            if(s.empty())
            {
                s.push(e[i]);
            }
            if(!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            if(!s.empty() && s.top() != '{')
            {
                s.push(e[i]);
            }

        }
   



        //after balanced part has been removed
        i++;
    }
    int count = 0;
    while (!s.empty())
    {
        
        char c1 = s.top();
        s.pop();
        char c2 = s.top();
        s.pop();
        if (c1 == c2)
        {
            count++;
        }
        else{
            count+=2;
        }
    }

return count;

}
int main()
{
    string s;
    cin>>s;

}