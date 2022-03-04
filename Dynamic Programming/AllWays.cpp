// this ques has more of a backtrack approach

// Each term has to be strictly greater than the previous term, so we always start checking from the previous number plus one.(At the very beginning, we start at 1.)We backtrack if the sum of the current expression exceeds “a”, since adding more terms will just increase the sum even further.We only go deeper if the current sum so far is strictly smaller than “a”.On the rare occasion that we get a sum of exactly “a”, it means we've found a solution This also means that we should backtrack since adding more terms will just increase the sum.
#include<iostream>
using namespace std;
#include<algorithm>
#include<cmath>
// int getAllWays(int a, int b)
// {
//     if(a <= 0 || b <= 0)
//     {
//         return 0;
//     }
//     int n = 0;
//     for(int i = 0; i <= n; i++)
//     {
//         n++;
//     }
//     int* output = new int [n];


// }
// //Brute recursive
// int getAllWays(int a, int b)
// {
//     if (a <= 0 || b <= 0)
//     {
//         return 0;
//     }
//     int sum = 0;
//     for(int i = 2; i <= a; i++)
//     {
//         sum += pow(i,b);
//         if(sum == pow(a,b))
//         {
//             return 1 + getAllWays(a-pow(i,b),b);
//         }
//         else if (sum > pow(a,b))
//         {

//         }
//     }
   
// }
int getAllWaysHelper(int x, int n, int curr_num = 1, int curr_sum = 0)
{
    int results = 0;
    int p = power(curr_num, n);
    while (p + curr_sum < x)
    {
        results += getAllWaysHelper(x, n, curr_num + 1, p + curr_sum);
        curr_num++;
        p = power(curr_num, n);
    }
    if (p + curr_sum == x)
    {
        results++;
    }
    return results;
}
int power(int num, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return power(num, n / 2) * power(num, n / 2);
    }
    else
    {
        return num * power(num, n / 2) * power(num, n / 2);
    }
}
int allWays(int a, int b,int curr, int sum)
{


    int p = power(curr,b);
    int ans = 0;
    while(sum + p < a)
    {
        ans += allWays(a,b,curr+1,sum+p);
        curr++;
         p = power(curr,b);
     
    }
    if (p == a)
    {
        ans++;
    }
    return ans;
}
// int getWays(int a, int b, int i, int j)
// {
//     if (a <= 1 || b <= 1)
//     {
//         return 0;
//     }
//     if(i >= j)
//     {
//         return 0;
//     }
//     int c = power(i,b);
//     int d = power(j,b);

//     if(c + d  < a)
//     {
//         return getWays(a, b, i + 1, j);
//     }
//     else if(c + d == a)
//     {
//         return 1 + getWays(a, b, i + 1, j - 1);
//     }
//     else{
//         //if greater we backtrack
//         return getWays(a, b,i,j - 1);
//     }
// }

int main()
{
    int a = 100;
    int b = 2;
    cout<<''<<endl;
}