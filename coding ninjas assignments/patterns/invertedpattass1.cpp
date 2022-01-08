#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i = 1;
    int c = n;
    while(i <= n)
    {
        int j = 1;
        while(j<=n-i+1)
        {
            cout<<c;
            j++;
            
        }
        cout<<endl;
        i++;
        c--;
    }

}