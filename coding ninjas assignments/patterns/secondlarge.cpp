#include<iostream>
using namespace std;
int second(int arr[], int n)
{
    for(int i = 0 ; i < n-1 ; i++){ 
    int small = arr[i];int minindex = i;
    for(int j = i+1 ; j < n ; j++)
    {
        if(arr[j] < small)
        {
            small = arr[j];
            minindex = j;

        }

    }
    int temp = arr[i];
    arr[i] = arr[minindex];
    arr[minindex] = temp;
    }
    return arr[n-2];

}
int main()
{
    int arr[] = {3,1,6,9,0,4};
    cout<<second(arr,6)<<endl;
}