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
void reversestring(char* a)
{
    int i = 0;
    int j = length(a)-1;
    while(i<j)
    {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

}
int main()
{
    char a[100];
    cin.getline(a,100);
    reversestring(a);
    cout<<a;
    // int i = 0;
    // int j = length(a)-1;
    // while(i < j)
    // {
    //     char temp = a[i];
    //     a[i] = a[j];
    //     a[j] = temp;
        
    //     i++;
    //     j--;
    // }
    // cout<<a;
    
    
}