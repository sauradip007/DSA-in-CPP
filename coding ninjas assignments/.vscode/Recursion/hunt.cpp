#include<iostream>
using namespace std;
bool check (int a[], int n,int x)
{
if(n == 0)
{
    return false;
}
bool smallAns  = check(a+1, n-1,x);
if(!smallAns)
{
    return false;
}
else{
    x = 3*x;
    check(a,n-1,x);
}
}