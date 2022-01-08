#include<iostream>
using namespace std;
int main()
{
    int num1,num2;
    
    int fib;
    num1 =1;
    num2 = 1;
    
    int n;
    cin>>n;
    if(n == 1)
    {
        cout<<num1<<endl;
    }
    else{
    for(int i = 1; i < n-1; i++)
    {
        fib = num1 + num2;
        num1 = num2;
        num2 = fib;
        
    }
    cout<<fib<<endl;
    }
}