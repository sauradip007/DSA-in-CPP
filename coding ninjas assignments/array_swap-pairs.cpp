#include<iostream>
using namespace std;
void swappair(int arr[], int n)
{
    if(n <= 1)
    {
        return;
    }
    int i = 0;
    swap(arr[i],arr[i+1]);
    return swappair(arr+2,n-2);

}
// void swappairs(int arr[], int n)
// {
//     int i = 0;
//     int j = n-1;
//     if(i % 2 == 0)
//     {
//     while(i < j)
//     {
        
        
//         swap(arr[i],arr[i+1]);
//         i+=2;
//     }
//     }
//     else{
//         while(i < j-1)
//         {
//             swap(arr[i], arr[i + 1]);
//             i += 2;
//         }
//     }
// }
int main()
{
    // int a[5] = {1,2,3,4,5};
    int n;
    cout<<"Enter n : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array : "<<endl;
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    swappair(arr,n);
    cout<<"The required array is : "<<endl;
    for(int i = 0 ; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

}