#include<iostream>
using namespace std;
#include<algorithm>
// int longestIncreasingSubsequence(int *arr, int n,int i)
// {
//     if(i >= n)
//     {
//         return 0;
//     }
//     for(int j = i-1; i >= 0; i--)
//     {
//         if(arr[i] > arr[j])
//         {
//             //increasing
//              return 1 + longestIncreasingSubsequence(arr,n,i+1);
//         }
//         else{
//             return longestIncreasingSubsequence(arr,n,i+1);
//         }
//     }
// }
// int longestIncreasingSubsequence(int *arr, int n)
// {
//     // Write your code here
//     // sort(arr,arr+n);
//         if(n <= 0)
//         {
//             return 0;
//         }

//     	for(int i = 1; i < n; i++)
//         {
//             if(arr[i] > arr[0])
//             {
//             return 1 + longestIncreasingSubsequence(arr+1,n-1);
//             }
         
//         }
        
//             return longestIncreasingSubsequence(arr + 1, n - 1);
        
// }

// Direct DP approach
int LIS_DP(int *input, int n)
{
    int *output  = new int[n];
    //each index of output stores LIS ending at index i in input so it will be of size n only

    // When there is 

    output[0] = 1; //when there is 1 element LIS will be that element itself
    for(int i = 1;i < n ; i++)
    {
        output[i] = 1; //initialising with 1
        for(int j = i-1; j >= 0; j--)
        {
            if(input[j] > input[i])
            {
                //I will not include in output array
                continue;
            }
            else{
              int possibleAns = output[j] + 1;
              if(possibleAns > output[i])
              {
                  output[i] = possibleAns;
              }
            }
        }

    }
    int bestAns = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        bestAns = max(bestAns,output[i]);
    }
}