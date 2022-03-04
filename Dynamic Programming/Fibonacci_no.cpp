#include<iostream>
using namespace std;
#include<algorithm>
int fib_iterative(int n) //Dynamic Programming approach
{
    int * ans = new int [n+1];
    ans[0] = 0;
    ans[1]= 1;
    //handling our smallest problems as these values are known
    for(int i = 2; i < n+1; i++)
    {
        ans[i] = ans[i-1] + ans[i-2];
        //ith fibo of array will be equal to its previous 2 entries sum 
    }
    return ans[n];
}








//recursive
int fibHelper(int n , int * ans)
{
    //currently ans has -1
    if( n <= 1)
    {
        return n;
    }
    //Check if output already exists
        // To do so we have to visit the ans array which currently contains -1 , on visiting a[n] if its -1 means we are visiting it the first time and if its not n we simply have to use that value from our ans array
        if(ans[n]  != -1)
        {
            return ans[n];
        }
        //first time reaching 
        //now we have to calculate our ans
        int a = fibHelper(n-1,ans);
        int  b = fibHelper(n-2,ans);

//This calculated output is saved for future use  in the array
        ans[n] = a + b;

        //This final output is returned

        return ans[n];

}
int fib (int n)
{
    //we need an n+1 size array to save our answers
    int * ans = new int [n+1];
    for(int i = 0; i < n+1; i++)
    {
        ans[i] = -1;
    }
    return fibHelper(n,ans);
}