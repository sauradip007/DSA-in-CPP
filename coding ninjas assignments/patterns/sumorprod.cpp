#include<iostream>
using namespace std;
int main()
{
    int n ; 
    
    cin>>n;
    int C;
    cin>>C;
    int sum = 0, product = 1;
    if(C== 1)
    {
        for(int i = 1; i <= n ; i++)
        {
            
            sum += i;
        }
        cout<<sum<<endl;
    }
    else if (C==2)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            
            product*=i;
        }
        cout<<product<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}