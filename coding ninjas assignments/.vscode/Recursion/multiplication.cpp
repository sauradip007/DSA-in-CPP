#include<iostream>
using namespace std;
int multiply(int m, int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    int sum=0;
    for(int  i = 0 ; i < n-1 ; i++){
        sum+=m;
    }
    return sum+m;
    
}
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<multiply(m,n)<<endl;
}