#include<iostream>
using namespace std;
int countZeroes(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int count = 0;
    int smallOutput = n/10;
    if(smallOutput == 0)
    {
        count++;
    }
    return count;
}
int main()
{
    int x;
    cin>>x;
    cout<<countZeroes(x)<<endl;
}