#include<iostream>
using namespace std;
int findDuplicate(int a[] , int n)
{
    int sum = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        sum+=a[i];
      
        
    }
   
    int mainSum = (((n-2)*(n-1))/2);
    int duplicate =  sum - mainSum;
    return duplicate;
 
}
int main()
{
    int a[9] = { 0, 7, 2, 5 ,4 ,7, 1, 3 ,6 };
    cout<<findDuplicate(a,9)<<endl;
}