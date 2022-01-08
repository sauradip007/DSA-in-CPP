#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int sti(char s[])
{
    int n = strlen(s);
    if (s[0] == '\0')
    {
        return 0;
    }
    int a = sti(s + 1);
    int b = s[0];
    b = b-48;
    return (b * pow(10, n - 1) + a);
}
int main()
{
    char s[100];
    cin.getline(s, 100);
   
    cout <<sti(s);
}