#include<iostream>
using namespace std;
void removedup(char s[])
{
    if(s[0] == '\0')
    {
        return;
    }
    if(s[0] != s[1])
    {
        removedup(s+1);
    }    
    else{
        int i = 1;
        for(;s[i] != '\0'; i++)
        {
            s[i-1] = s[i];
        }
        s[i - 1] = s[i];
        removedup(s);
    }
}
int main()
{
    char str[100];
    cin.getline(str,100);
    removedup(str);
    cout<<str<<endl;
}