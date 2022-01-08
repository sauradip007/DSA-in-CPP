#include<iostream>
using namespace std;
#include "stacks_LL.h"
#include<stack>
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.top()<<endl;//60
    s.pop(); //deletes 60 and size is decremented
    cout<<s.top()<<endl; //50 is top
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;

}