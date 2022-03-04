#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of the arrays : ";
    cin>> n;
    // Initialising both the arrays
    int * a = new int [n];
    int *b = new int [n];
    cout<<"Enter the first array"<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the second array "<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    cout<<"The first array entered is : "<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
        
    
    }cout<<endl;
    cout<<"The second array entered is : "<<endl;
    for(int j = 0 ; j < n ; j++)
    {
        cout<<a[j]<<" ";
    }cout<<endl;
    sort(a,a+n);
    sort(b,b+n);
    int i = 0; int j = 0;
    cout<<"The intersected array given by : "<<endl;
    while(i < n && j < n)
    {
        if(a[i] < b[j])
        {
            i++;
        }
        else if( a[i] > b[j])
        {
            j++;
        }
        else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }cout<<endl;
    
}