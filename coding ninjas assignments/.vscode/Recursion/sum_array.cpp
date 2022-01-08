#include<iostream>
using namespace std;
int sum(int a[], int size)
{
    if(size == 0)
    {
        return 0;
    }
    int smallerOutput = sum(a+1, size-1);
    return smallerOutput + a[0];
}
int main()
{
    int a[5] = {1,2,3,4,5};
    cout<<sum(a,5)<<endl;
}