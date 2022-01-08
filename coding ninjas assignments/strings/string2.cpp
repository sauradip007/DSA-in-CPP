#include<iostream>
using namespace std;
int main()
{
    char a[10];
    cin>>a;
    char b,c;
    cin>>b>>c;
    for(int i = 0 ; a[i] != '\0' ; i++)
    {
        if(a[i] == b)
        {
            a[i] = c;
        }
        cout<<a[i];
    }
}