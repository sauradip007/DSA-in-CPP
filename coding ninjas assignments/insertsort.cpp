#include<iostream>
using namespace std;
    void insertsort(int arr[] , int n)
    {
        
        for(int i = 1; i < n; i++)
        {
            int current = arr[i];
            int j;
            for(j = i-1 ; j >= 0 ; j--)
            {
                if (current <= arr[j])
                {
                    arr[j+1] = arr[j];
                }
                else{
                    break;
                }

            }
            arr[j+1] = current;
        }
    }
    int main()
    {
       int n;
       cin>>n;
       int arr[n];
       for(int i = 0 ;i < n ; i++)
       {
           cin>>arr[i];
       }
        insertsort(arr,6);
         for(int i = 0 ;i < 6;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    }
