#include<iostream>
#include<cstring>
using namespace std;
void replacex(char s[], char c, char d)
{
    if(s[0] == '\0')
    {
        return;
    }
    if(s[0] != c)
    {
        replacex(s+1,c,d);
    }
    else{
        replacex(s+1,c,d);
        s[0] = d;
     
    }

}
int main()
{
    char str[100];
    char c;
    char d;
    cin.getline(str, 100);
    cin>>d;
    cin>>c;
    
    replacex(str,c,d);
    cout<<str;
}