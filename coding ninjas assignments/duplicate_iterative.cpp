#include<iostream>
using namespace std;
void sortArray(int a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
int findDuplicate(int a[] , int n)
{
    sortArray(a,n);
    int i = 0;
    while(i < n-1)
    {
        if(a[i] == a[i+1])
        {
            return a[i];
            break;
        }
        i++;
    }
    return -1;
}
int main()
{
    int a[9] = { 0, 7, 2, 5 ,4, 7, 1, 3 ,6 };
    cout<<findDuplicate(a,9)<<endl;
}