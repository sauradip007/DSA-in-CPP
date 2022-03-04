#include<iostream>
using namespace std;
void swapelem(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}//creating a swapping function
int partition(int a[], int start, int end)
{
    int k = start;
    int count_smaller = 0;
    int pivot = a[k];
    for(int i = k+1; i <= end; i++)
    {
        if(a[i] < pivot)
        {
            count_smaller++;
        }
    }
    int index = start + count_smaller;
    swapelem(a,k,index);
//partitioning the elements
while(k < index && index <= end)
{
    if(a[k] <= pivot)
    {
        k++;
    }
    else if(a[end] > pivot)
    {
        end--;
    }
    else{
        swapelem(a,k,end);
        k++;
        end--;
    }
}






return index;
}
void quickSort(int a[], int start, int end)
{
    if( start >= end)
    {
        return;
    }
    int p = partition(a,start,end);
    quickSort(a,start,p-1);
    quickSort(a,p+1,end);
}
// void swapel(int a[], int i, int j)
// {
//     int temp = a[i];
//     a[i] = a[j];
//     a[j] = temp;
// }
// int partition(int a[], int start, int end)
// {
//     int count_smaller = 0;
//     int k = start;
//     int pivot = a[k];
//     for(int i = k+1; i <= end; i++)
//     {
//         if(a[i] <  pivot)
//         {
//             count_smaller++;
//         }
//     }
//     //no of smaller elements counted
//     int index = start + count_smaller;
//     swapel(a,k,index);
//     //swap both elements
//     //now partition them accordingly
//     while(k < index && index <= end)
//     {
//         if(a[k] <= pivot)
//         {
//             k++;
//         }
//         else if(a[k] > pivot)
//         {
//             end--;
//         }
//         else{
//             swapel(a,k,end);
//             k++;
//             end--;
//         }
//     }
//     return index;
// }
// void quickSort(int a[], int start, int end)
// {
//     if(start >= end)
//     {
//         return;
//     }
//     int part = partition(a,start,end);
//     quickSort(a,start,part-1);
//     quickSort(a,part+1,end);
// }
int main()
{
    int a[7] = {5, 9, 8, 3, 2, 7, 1};
    quickSort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}