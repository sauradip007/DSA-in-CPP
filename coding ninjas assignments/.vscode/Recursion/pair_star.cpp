#include<iostream>
#include<cstring>
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
void pairstar(char s[])
{
    int n = length(s);
    if(s[0] =='\0')
    {
        return;
    }
    pairstar(s+1);
    if(s[0] != s[1])
    {
        return;
    }
    else{
        for(int i = n+1; i >= 1;i--)
        {
            s[i+1] = s[i];
        }
        s[1] = '*';

    }

}
int main()
{
    char s[00];
    cin.getline(s,100);
    pairstar(s);
    cout<<s;
}