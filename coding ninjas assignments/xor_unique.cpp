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
int xor_unique(int a[] , int n)
{
    // sortArray(a,n);
    int i = 0 ;
    int res = 0;
    if(n== 1)
    {
        return a[0];
    }
    // while(i < n-1)
    // {
    //      res = a[i] ^ a[i+1];
    //     if(res != 0)
    //     {
    //         return a[i];
    //         break;
    //     }
      

    // }
    int x;
    for(int i = 0; i < n; i++)
    {
        a[i] = a[i]^a[i+1];
        x = a[i];
    }
    return x;
   
}
int main()
{
    int a[7] = {2 ,3, 1, 6 ,3, 6 ,2};
    cout<<xor_unique(a,7)<<endl;
    
}