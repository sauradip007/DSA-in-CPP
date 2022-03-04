#include<iostream>
using namespace std;

// long staircase(int n)
    // {
    // 	//Write your code here
    //      long count = 0;
    //     if(n == 0)
    //     {
    //         return 1;
    //     }
    //     if(n == 1)
    //     {
    //         return 1;
    //     }
    //     if(n == 2)
    //     {
    //         return 2;
    //     }
    //     count += staircase(n-1);
    //     count += staircase(n-2);
    //     count += staircase(n-3);
    //     return count;

    // }

    // DP
    long staircaseHelper(int n, long *ans)
{
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
    return ans[n];
}

// memoization
// long staircaseHelper(int n, long *ans)
// {
//     long count = 0;
//     if(n == 0)
//     {
//         return 1;
//     }
//     if(n == 1)
//     {
//         return 1;
//     }
//     if(n == 2)
//     {
//         return 2;
//     }
//     if(ans[n] != -1)
//     {
//         return ans[n];
//     }
//     count += staircaseHelper(n-1,ans);
//     count += staircaseHelper(n-2,ans);
//     count += staircaseHelper(n-3,ans);
//     ans[n] = count;
//     return ans[n];
// }

long staircase(int n)
{
    long *ans = new long[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return staircaseHelper(n, ans);
}