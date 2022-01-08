#include<iostream>
#include<cstring>
using namespace std;
bool checkPal(char s[])
{
    int l = strlen(s);
    if(s[0] == s[l-1])
    {
        return true;
        for (int i = 1; i < l - 1; i++)
        {
            if (s[i] == s[l - i - 1])
            {
                return true;
            }
          
        }
    }
    return false;

}
int main()
{
    char s[100];
    cin.getline(s,100);
    cout<<checkPal(s)<<endl;
}