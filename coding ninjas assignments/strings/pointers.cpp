#include<iostream>
using namespace std;
int main()
{
    int a = 100, b = 200;
    int *p = &a, *q = &b;
    cout<<a<<" "<<b<<endl;
    cout<<&a<<" "<<&b<<endl;
    cout<<p<<" "<<q<<endl;
    p = q;
    cout<<p<<" "<<q<<endl;
}