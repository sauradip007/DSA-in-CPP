#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    bool flag;
    for(int i = 0 ;  i < n ; i++)
    {
        cin>>arr[i];
    }
    int prev = arr[0];
    int curr = arr[1];
    int  i = 0;
    while(i < n)
    {
        if(prev ==  curr)
        {
            flag  = false;


        }
        else if ( prev < curr)
        {
            flag = true;
        }
        else if (prev > curr)
        {
            flag = false;
        }
        i++;
        prev++;
        curr++;

    }

}