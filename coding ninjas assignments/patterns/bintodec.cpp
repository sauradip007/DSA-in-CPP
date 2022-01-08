#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int base = 0;
    int temp;
    
    int count = 0;
    while(n != 0)
    {
        
        
        temp = n % 10;
        n = n/10;
        base += pow(2,count) *temp;
        count++;

        
    }
    cout<<base<<endl;
}