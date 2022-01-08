#include<iostream>
using namespace std;
// void sortArray(int a[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (a[j] < a[i])
//             {
//                 int temp = a[j];
//                 a[j] = a[i];
//                 a[i] = temp;
//             }
//         }
//     }
// }
int checkrotation(int a[], int n)
{
    // int count = 0;
    // for(int i = 0; i < n-1 ;i++)
    // {
    //     for(int j = i+1; j < n ; j++)
    //     {
    //         if(a[j] < a[i])
    //         {
    //             count++;
    //         }
           
    //     }
    // }
    // return count;
//     5
// 3 6 8 9 10 - 0
// 4
// 10 20 30 1 - 3
    int i = 0;
    int count = 1;
    if(n == 0)
    {
        return 0;
    }
    while(i < n)
    {
        if(a[i] < a[i+1])
        {
            count++;

        }
        else{
            break;
        }
        i++;
    }
    if(count == n)
    {
        return count-n;
    }
return count;
}
int main()
{
    int a[4] = {10,20,30,1};
    cout<<checkrotation(a,5)<<endl;
}