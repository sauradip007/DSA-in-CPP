#include<iostream>
#include<string>
using namespace std;
int main()
{
    string i = "Geeks";
    //i want gi
    //index 0
    cout<<i.substr(1,1) + i.substr(2,1)<<endl;
    //i want ai
    //index 1
    cout << i.substr(0,1) + i.substr(2,1) << endl;
    //i want ag
    //index 2
    int x = i.substr(0,2);
    cout << i.substr(0,1) + i.substr(1,1) << endl;
string c = i.substr(0,2);
cout<<(int)i.substr(0,2)<<endl;
    cout << i.substr(0,0) << endl;
}
