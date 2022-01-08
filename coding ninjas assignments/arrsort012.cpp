#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int i = 0;
    int j = n-1;
    for(int p = 0 ;p < n ; p++)
    {
        cin>>arr[p];
    }
    
        for(int i = 0 ; i < n ; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
}