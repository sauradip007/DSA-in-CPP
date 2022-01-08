#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count = 0 ;
   
    for(int i = 1; i <= n+1, count <= n-1 ; i++ )
    {
        int m = 3*i + 2;
        if(m % 4 != 0){
        cout<<m<<" ";
        count++;
        }
        else{
            continue;
        }
        
        
    }cout<<endl;
}