#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    int sum = 50;
    for(int i = 0 ; i < n ; i++)
    {
        sum = sum+=arr[i];
         if(sum > 100)
        {
            sum = 100;
        }
      
    }
   
    cout<<sum<<endl;
}