#include <iostream>
#include <cstring>
using namespace std;
int length(char a[])
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
void replacepi(char s[])
{
    int n = length(s);
    if (n <= 1)
    {
        return;
    }
    replacepi(s + 1);
    if (s[0] != 'p' && s[1] != 'i')
    {
        return;
    }
    else
    {

        for (int i = n+1; i >=2; i--)
        {
          s[i+2] = s[i];
        }
        s[0] = '3';
        s[1] = '.';
        s[2] = '1';
        s[3] = '4';
    }
}
int main()
{
    char str[100];
    cin.getline(str, 100);

    replacepi(str);
    cout << str;
}