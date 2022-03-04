#include<iostream>
#include<algorithm>
using namespace std;
// DP
int maxMoney_DP(int *arr, int n , int i, int **output)
{
    int **output = new int *[n + 1];
    for (int j = 0; j <= n; j++)
    {
        output[j] = new int[n + 1];
    }
    // At n = 0 , we know maxloot is 0
    for(int i = 0; i <= n; i++)
    {
        output[i][0] = 0;
    }
    for(int j = 1; j <= n; j++)
    {
        output[0][j] = 1;
    }
    
}
//mem 
int maxMoney_mem(int *arr, int n , int i, int * output)
{
    // Base cases
    if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return arr[i];
        }
        if (n == 2)
        {
            return max(arr[i], arr[i + 1]);
        }
        if (n == 3)
        {
            return max(arr[i] + arr[i + 2], arr[i + 1]);
        }
        if(output[n] != -1)
        {
            return output[n];
        }
        // Recursive calls
        if (n % 2 == 0)
            {
                int a = maxMoney_mem(arr, n - 1, i + 1,output);
                int b = arr[i] + maxMoney_mem(arr, n - 2, i + 2,output);
                output[n] = max(a, b);
              
            }
            else{
                        int c = maxMoney_mem(arr, n - 2, i + 2,output);
                        int d = arr[i] + maxMoney_mem(arr, n - 1, i + 1,output);
                        output[n]= max(c, d);
                       
            }
            return output[n];
}
//Brute force recursion
// int maxMoney_mem(int *arr, int n, int i, int **output)
// {

//     // // second approach
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n == 1)
//     {
//         return arr[i];
//     }
//     if (n == 2)
//     {
//         return max(arr[i], arr[i + 1]);
//     }
//     if (n == 3)
//     {
//         return max(arr[i] + arr[i + 2], arr[i + 1]);
//     }
//     //Base case
//     // Check array
//     if(output[n][i] != -1)
//     {
//         return output[n][i];
//     }
//     // Recursive calls
//     if (n % 2 == 0)
//     {
//         int a = maxMoneyLootedHelper(arr, n - 1, i + 1);
//         int b = arr[i] + maxMoneyLootedHelper(arr, n - 2, i + 2);
//         output[n][i] = max(a, b);
//         return output[n][i];
//     }
//     else
//     {
//         // int b = maxMoneyLootedHelper(arr,n, i+1);
//         int c = maxMoneyLootedHelper(arr, n - 2, i + 2);
//         int d = arr[i] + maxMoneyLootedHelper(arr, n - 1, i + 1);
//         output[n][i] = max(c, d);
//         return output[n][i];
//     }
// }
int maxMoneyLootedHelper(int *arr, int n, int i)
{
    //The 2-D array will be of size n*i
    //The element at output[n][i] represents nth house at ith index will give how much max loot
// int **output = new int*[n+1];
// for(int j = 0; j <= n; j++)
// {
//     output[j] = new int [i+1];
//     for(int k = 0; k <= i ; k++)
//     {
//         output[j][k] = -1;
//     }
// }
int *output  = new int [n+1];
for(int i = 0 ; i <= n; i++)
{
    output[i] = -1;
}
return maxMoney_mem(arr,n,i,output);
}
    // // including first element
    // // not including first element

    // // second approach
    // if (n == 0)
    // {
    //     return 0;
    // }
    // if (n == 1)
    // {
    //     return arr[i];
    // }
    // if (n == 2)
    // {
    //     return max(arr[i], arr[i + 1]);
    // }
    // if (n == 3)
    // {
    //     return max(arr[i] + arr[i + 2], arr[i + 1]);
    // }
    // 
    //

    // 
    // if (n % 2 == 0)
    // {
    //     int a = maxMoneyLootedHelper(arr, n - 1, i + 1);
    //     int b = arr[i] + maxMoneyLootedHelper(arr, n - 2, i + 2);
    //     return max(a, b);
    // }
    // else
    // {
    //     
    //     int c = maxMoneyLootedHelper(arr, n - 2, i + 2);
    //     int d = arr[i] + maxMoneyLootedHelper(arr, n - 1, i + 1);
    //     return max(c, d);
    // }
}