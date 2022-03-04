#include <iostream>
using namespace std;
void merge(int a[], int start, int end)
{
    int b[end - start + 1];//MISTAKE
    int mid = (start + end) / 2;
    int j = mid + 1;
    int i = start;
    int k = end;
    int c = 0;
    while (i < mid+1 && j <= k)
    {
        if (a[i] < a[j])
        {
            b[c] = a[i];
            // j++;
            // start++;
            i++;
            c++;
        }
        else
        {
            b[c] = a[j];
            j++;
            c++;
            
        }
    }
    while (i < j )
    {
        b[c] = a[i];
        i++;
        c++;
    }
    while (j <= k)
    {
        b[c] = a[j];
        c++;
        j++;
    }
    i = start;
    for (; i <= k; i++)
    {
        a[i] = b[i - start];
    }//here 0th element of b corresponds to start th element of a b is a separate entity everytime recursion is called but we are merging everything into array a where count will continue
  
}
void mergeSort(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, end);
}
int main()
{
    int a[5] = {5, 3, 8, 7, 1};
    mergeSort(a, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
