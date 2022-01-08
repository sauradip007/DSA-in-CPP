#include<iostream>
using namespace std;
void sortArray(int a[],int n)
{
    for(int i = 0; i < n-1 ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(a[j] < a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }

        }
    }
}
void intersection(int a[], int b[], int m , int n)
{
    // int i = 0;
    // int j = 0;
    // for(int i = 0; i < m ;i++)
    // {
    //     for(int j = 0; j < n ; j++)
    //     {
    //         if(a[i] == b[j])
    //         {
    //             cout<<a[i]<< " ";
    //         }
    //     }
    // }cout<<endl;
    sortArray(a,m);
    sortArray(b,n);
    int  i = 0;
    int j = 0;
    while(i < m && j < n)
    {
        if(a[i] < b[j])
        {
            j++;
        }
        else if(a[i] > a[j])
        {
            i++;
        }
        else{
            cout<<b[j]<<" ";
            i++;
            j++;
        }
    }cout<<endl;


}
int main()
{
    int a[6] = { 2, 6, 8, 5 ,4, 3 };
    int b[4] = {2,3,4,7};
    intersection(a,b,6,4);
}