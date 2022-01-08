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
    bool matching = false;
    for(int i = 0 ; i < n; i++)
    {
        matching = false;
        for(int j = 0; j < n ; j++)
        {
            if(arr[i] == arr[j] && i!=j)
            {
                matching = true;
                break;
            }
            else{
                cout<<arr[i]<<" ";
            }
        }
    }cout<<endl;
}