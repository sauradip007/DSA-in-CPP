#include<iostream>
#include<cstring>
using namespace std;
void print(string i,int x, string o)
{
    if (x == i.length())
    {
        cout << o << endl;
       return;
    } // base case

    // print(i.substr(1),o);//recursive call
    // print(i.substr(1), o+ ch);
    for (int j = 0; j < i.length(); j++)
    {
        print(i, x + 1, o);
       char temp = i[j];
        // i[j] = i[j+1];
        print(i, x + 1, o + temp);
    }
    char ch2 = i[0];
    print(i,x+1,o + ch2);
}
int main()
{
    string i = "abc";
    string o;
    int x = 0;
    print(i,x,o);
}