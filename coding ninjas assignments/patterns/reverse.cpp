#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int rev = 0;
    rev = n%10;
    while(n != 1)
    {
         
        n = n/10; //15
        
        
       
       rev = rev*10 + (n%10);
       
    }
    cout<<rev<<endl;
}