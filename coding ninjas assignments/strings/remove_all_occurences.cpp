#include<iostream>
using namespace std;
int main()
{
    char a[100];
    cin.getline(a,100);
    char c;
    cin>>c;
    int i = 0;
    
    while(a[i] != '\0')
    {
        int count = 0;
        if(a[i] == 'c')
        {
          
          count++;
          i = count+i+1;
          
        }
        cout<<a[i];
        i++;
    }

}
