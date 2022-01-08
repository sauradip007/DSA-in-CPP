#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s1 = "abc";
    string s2 = "def";
    string s = s1 +  s2;
    cout<<s<<endl;
    cout<<s.size()<<endl;
    cout<<s.substr(3)<<endl;
    cout<<s.substr(3,2)<<endl;
    cout<<s.find("def")<<endl;
}