#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;
void selectsort(int arr[], int n)
{
    for(int i = 0 ; i < n-1 ; i++){ //indicates which round its in
    //int small = INT_MAX;
    int small = arr[i];int minindex = i;
    /*for(int i = 0 ; i < n ; i++)
    {
        //small = min(small,arr[i]);
    }*/
    for(int j = i+1 ; j < n ; j++)//find minimum and index of the element it is to be updated with
    {
        if(arr[j] < small)
        {
            small = arr[j];
            minindex = j;

        }

    }
    //swap
    int temp = arr[i];
    arr[i] = arr[minindex];
    arr[minindex] = temp;
    }

}
int main()
{
    int arr[] = {3,1,6,9,0,4};
    selectsort(arr,6);
    for(int i = 0 ; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
