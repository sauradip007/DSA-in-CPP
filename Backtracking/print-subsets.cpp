#include<iostream>
using namespace std;
void subset(int a[],int output[], int n, int m = 0)
{
    if(n == 0)
    {
        for(int i = 0; i < m ; i++)
        {
            cout<<output[i]<<" ";
        }cout<<endl;
        return;
    }
    //not including
    subset(a+1,output,n-1,m);
    int newOutput[1000];
    for(int j = 0 ; j < m ; j++)
    {
        newOutput[j] = output[j];

    }
    newOutput[m] = a[0];//appending the first element which is not being considered
    subset(a+1,newOutput,n-1,m+1);//including call , size of output array increased by 1

}