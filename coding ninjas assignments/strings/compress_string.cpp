#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[100];
    cin.getline(a,100);
    int i = 0;
    while(a[i] != '\0')
    {
        int count = 0;
        if(a[i+1] == a[i])
        {
            count++;
            i++;
            

        }
        cout<<a[i];
        cout<<count;
        i++;
    }
}