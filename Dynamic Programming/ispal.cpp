#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
bool isPal(string s,int start, int end)
{
    if(start > end)
    {
        return false;
    }
    if(start == end)
    {
        return true;
    }
    // int l = s.length();
    // end = s.length() -1;
   if(s[start] == s[end])
   {
       return isPal(s,start+1,end-1);
   }
   return false;
}
bool palypal(string s)
{
    stack<int>sp;
    for(int i = 0;i < s.length(); i++)
    {
        int t = sp.top();
        sp.push(s[i]);
        if(t == sp.top())
        {
            sp.pop();
        }

    }
    if(sp.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    string s = "bad";
    cout<<isPal(s,0,s.length()-1)<<endl;
}