#include <iostream>
using namespace std;
int firstIndex(int a[], int size, int x)
{
    if (size == 0)
    {
        return -1;
    }
    if (a[0] == x)
    {
        return 0;
    }

    int ans = firstIndex(a + 1, size - 1, x);
    if(ans==-1)
    {
        return ans;
    }
    else{
        return ans+1;
    }
}
int main()
{
    int a[5] = {5,5,6,5,6};
    int x  = 6;
    cout<<firstIndex(a,5,x)<<endl;
}