#include<iostream>
using namespace std;
int lastIndex(int a[] , int size , int x)
{
    if(size==0)
    {
        return -1;
    }
    int smallOutput = lastIndex(a+1, size-1, x);
    if(smallOutput == -1)
    {
        if(a[0] == x)
        {
            return 0;
        }
        else{
            return -1;
        }
    }
    
        return smallOutput+1;
   
}
int main()
{
    int a[5] = {5, 5, 6, 5, 6};
    int x = 6;
    cout << lastIndex(a, 5, x) << endl;
}