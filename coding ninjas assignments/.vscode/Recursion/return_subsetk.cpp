#include<iostream>
using namespace std;
int subsetk(int a[], int i, int k, int n,int output[][50])
{
    if(n==0 )
    {
        output[0][0] = 0;
        return 1;
    }
    if(i==n)
    {
        for(int i = 0; i < n; i++)
        {
            output[i][50] = a[i];
        }
        return i;
    }

    int number_of_columns1;
    int number_of_columns2;
    int o1[1000][50];
    int o2[1000][50];
    int smallOutput1 = subsetk(a,i+1,k-a[i],n-1,o1);//considering a[0]
    int smallOutput2 = subsetk(a,i+1,k,n-1,o2); //not considering a[0]
    // creating array1 with small output 2
    for(int i = 0; i <smallOutput1 ; i++)
    {
        number_of_columns1 = o1[i][0];
        output[i][0] = o1[i][0] + 1;
        output[i][1] = a[0];
        for(int j = 1; j <= number_of_columns1 ; j++)
        {
           output[i][j+1] = o1[i][j];

        }
    }
    for(int i = 0 ; i < smallOutput2 ;i++)
    {
        number_of_columns2 = o2[i][0];
        output[i+smallOutput1][0] = o2[i][0];
        for(int j = 1; j <= number_of_columns2; j++)
        {
            output[i+smallOutput1][j] = o2[i][j];
            
        }
    }
    return smallOutput1 + smallOutput2;

}
int main()
{
    int a[9] = { 5 ,12 ,3 ,17, 1, 18 ,15, 3 ,17 };
    int i = 0;
    int output[1000][50];
    cout<<subsetk(a,i,6,9,output)<<endl;
}