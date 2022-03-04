#include<iostream>
using namespace std;
void bubblesort(int arr[] , int n)
{
    for(int j = 0 ; j < n-1; j++){
    for(int i = 0 ; i < n-1-j ; i++)
    {
        if(arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
         }
    }
    }
}
int main()
{
   int n;
       cin>>n;
       int *arr = new int[n];
       for(int i = 0 ;i < n ; i++)
       {
           cin>>arr[i];
       }
        bubblesort(arr,n);
         for(int i = 0 ;i < n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}