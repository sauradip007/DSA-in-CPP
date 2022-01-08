#include<iostream>
#include<cstring>
using namespace std;
void removex(char s[])
{
    if(s[0] == '\0'){
        return;
    }
    if(s[0] != 'x')
    {
        removex(s+1); //calling for s+1 since s[0] has no meaning if its not x
        }else{
            int i =1;
            for(; s[i] != '\0'; i++)
            {
                s[i-1] = s[i];

            }
            s[i-1] = s[i];//if x is still present instead of traversing forward(eg: xabc)
            removex(s);

        
    }
}
int main()
{
    char str[100];
    cin.getline(str,100);
    removex(str);
    cout<<str<<endl;
}