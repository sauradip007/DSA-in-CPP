#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {}
    int n;
    cin >> n;

    int arr[n];
    int s = 0;
    int e = n-1;
    int val = 1;
    
  
        while(e > s && e != (n-1)/2)
    {
        arr[s] = val;
        val++;
        arr[e] = val;
        val++;
        s++;
   
    
        e--;
    
        
    }
    
        
    for(int j = 0 ; j < n ; j++)
    {
        cout<<arr[j]<<" ";
    }cout<<endl;
    }
}