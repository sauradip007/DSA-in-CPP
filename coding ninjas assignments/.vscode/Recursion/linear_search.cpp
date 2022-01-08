#include<iostream>
using namespace std;
bool checkNumber(int a[] , int n,int x)
{
    if(n==0)
    {
        return false;
    }
    bool checkSmaller= checkNumber(a+1,n-1,x);
    if(checkSmaller)
    {
        return true;
    }
        if(a[0] == x)
        {
            return true;
        }
        else{
            return false;
        }
    

}
int main()
{
    int a[5] = {1,2,3,4,5};
    int x = 7;
    cout<<checkNumber(a,5,7)<<endl;
}
