#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    stack<int>s;
    queue<int>q;
    int a[5] = {5,6,7,8,9}; //m stack
    int b[4] = {1,2,3,4};//n queue
    int c[10];
    for(int i = 0; i < 5; i++)
    {
        s.push(a[i]);
    }
    for(int i = 0 ; i < 4 ; i++)
    {
        q.push(b[i]);
    }
    if(s.top() > q.front())
    {
        int i = 0;
        while(!q.empty() || i != 10)
        {
            int temp = q.front();
            q.pop();
            c[i] = temp;
            i++;
        }
        int j = i+1;

        while(!s.empty() || j != 10)
        {
            int temp = s.top();
            s.pop();
            c[j] = temp;
            j++;
        }
        for(int i = 0; i < 10 ; i++)
        {
            cout<<a[i]<<" ";
        }cout<<endl;
    }
   

}