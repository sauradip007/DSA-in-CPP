#include<iostream>
#include<stack>
#include<queue>
using namespace std;
bool redundant(string e)
{
    // int count;
    // stack<char>s;
    // int i = 0;
    // while(/*e[i] != '\0'*/ !s.empty())
    // {
    // while ( s.top() != ')')
    // {
    //     s.push(e[i]);
    //     i++;
    // }
    // int count = 0;
    // while (s.top() != '(')
    // {
    //     s.pop();
    //     count++;
    // }
    
    // }

    // if(count = 0)
    // {
    //     return true;
    // }
    // return false;
    int count;
    stack<char>s;
    // int i = 0;
    // s.push(e[i]);
    // while(!s.empty())
    // {
    //     while(s.top() != ')' && e[i]  != '\0')
    //     {
    //         s.push(e[i]);
    //         i++;
    //     }
    //     s.pop();
    //     count = 0;
    //     while(s.top() != '(')
    //     {
    //         s.pop();
    //         count++;
    //     }
    //     s.pop();
    // }
    // if(count == 0)
    // {
    //     return true;
    // }
    // return false;
    int count;
    int i = 0;
    while(e[i] != '\0')
    {
        if(e[i] != ')')
        {
            s.push(e[i]);

        }
        else{
            count = 0;
            while(s.top() != ')')
            {
                s.pop();
                count++;
            }
            if(count == 0)
            {
                return true;
            }

        }
        i++;
    }
return false;
}
int main()
{
    string s;
    cin>>s;
    cout<<redundant(s)<<endl;
}