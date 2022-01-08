#include<iostream>
using namespace std;
int length(char a[])
{
    int count = 0;
    for(int i = 0 ; a[i] != '\0';i++)
    {
        count++;

    }
    return count;
}
int main()
{
    
    char a[100];
    cin.getline(a,100);
    int i = 0;
    while(a[i] != '\0')
    {
        if(a[i] == ' ')
        {
            i++;
        }
        cout<<a[i];
        
        i++;
        
        
    }
    
}