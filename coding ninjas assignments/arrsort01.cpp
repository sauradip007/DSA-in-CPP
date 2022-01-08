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
    while(i < j)
    {
       if(arr[i] == 0)
       {
           i++;
       }
       else{
           if(arr[j] == 1)
           {
               j--;
           }
           else{
               int temp = arr[j];
               arr[j] = arr[i];
               arr[i] = temp;

           }
       }
            
        }
        for(int i = 0 ; i < n ; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
}
     
        

