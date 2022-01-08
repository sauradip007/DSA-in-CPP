#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   
    string c;
    cout<<"Enter string : "<<endl;
    getline(cin,c);
    // cin>>c;
    int x;
    cout<<"Enter from where you need to start sub : "<<endl;
    cin>>x;
    int y;
    cout<<"Enter upto which character do you have to find sub : "<<endl;
    cin>>y;
    string str;
    if(x >= 0 && y < c.length())
    {
     str = c.substr(x,y);
    }
    cout<<"Substring is : "<<str<<endl;
    cout<<"Length of substring is : "<<str.length()<<endl;

}