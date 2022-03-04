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
    char a[10] = "ABCD";
    int l = length(a);
    cout<<l<<endl;
   
}