#include<iostream>
using namespace std;
void sortArray(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
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
int maxprofit(int budget[], int n, int m=0 , int x=0)
{
    if(n==0)
    {
        return 0;
    }
    sortArray(budget, n);

    int profit1 = maxprofit(budget + 1, n - 1,m,x);

    // return profit1;
    // int profit2 = maxprofit(budget,n,m,x);
    // if(budget[0] >= profit1)
    // {
    //     return budget[0]*m;
    // }
    m = 0;
    int profit2;
   
    
    x = budget[0];
    for(int i = 0; i < n ; i++)
    {
        if(x <= budget[i])
        {
            m++;

        }
        
        
    }
    
    profit2 = m*x;
    if(profit2 > profit1)
    {
        return profit2;
    }
    return profit1;

}
int main()
{
    int a[5] = {34 ,78 ,90 ,15, 67};
    cout<<maxprofit(a,5,0,0)<<endl;
}