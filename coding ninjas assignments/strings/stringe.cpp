#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    char s[100];
    char t[100];
    cin>>s;
    cin>>t;
    int x = strcmp(s,t);
    cout<<to_string(x)<<endl;
    return 0;
}