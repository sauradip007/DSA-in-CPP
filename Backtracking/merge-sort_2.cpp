#include<iostream>
using namespace std;

void merge(int a[], int start, int end)
{
    int* b = new int[end-start+1];
    // int b[end-start+1];
    int mid = (start + end) / 2;
    int j = mid + 1;
    int i = start;
    int k = end;
    int c = 0;//keeps track of elements in b
    //merge 2 sorted array into a 3rd array b 
    while(i <= mid && j <= k)
    {
        if(a[i] < a[j])
        {
            b[c] = a[i];
           i++;
           c++;
        }
        else{
            b[c] = a[j];
            j++;
            c++;
        }

    }
    //now for the remaining elements
    while(i <= mid)
    {
        b[c] = a[i];
       i++;
       c++;
    }
    while(j <= k)
    {
        b[c] = a[j];
        c++;
        j++;
    }
    i = start;
    //reinitialising i to start
    for(; i <= end; i++)
    {
      a[i]   = b[i-start];
    }

}



void mergeSort(int arr[], int start, int end)
{
    //base case
    if(start >= end)
    {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
    //both halves are sorted
    //now merge 2 sorted halves
}
int main()
{
    int a[5] = {5,1,3,7,8};
    mergeSort(a,0,4);
    for(int i = 0; i < 5 ; i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;

 
}