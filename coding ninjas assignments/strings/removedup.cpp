#include<iostream>
using namespace std;
int main()
{
    char a[100];
    cin.getline(a,100);
    
    int i = 0;
    int count = 0;
    while(a[i] != '\0')
    {
        if(a[i] == a[i+1])
        {
          i++;
        }
        cout<<a[i];
        i++;
    }

}
