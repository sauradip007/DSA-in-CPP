#include<iostream>
using namespace std;
void printsubset(int a[],int n,int output[], int m=0)
{
    if(n==0)
    {
        for(int i = 0; i < m; i++)
        {
            cout<<output[i]<<" ";
        }
        cout << endl;
        return;
    }
   
    int newOut[1000];
   
    printsubset(a + 1, n - 1, output, m); //case not considering a[0]
    for (int i = 0; i < m; i++)
    {
        newOut[i] = output[i];
    }
    newOut[m] = a[0];
    printsubset(a+1,n-1,newOut,m+1); //case considering a[0]
}
int main()
{
    int a[3] = {15,20,12};
    int b[1000];
    printsubset(a,3,b,0);
}



