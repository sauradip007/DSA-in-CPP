#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int n1 = (n+1)/2;
    int n2 = n/2;
    int i = 1;
    while(i <= n1)
    {
        int spaces = 1;
        while(spaces <= n1-i){
            cout<<" ";
            spaces++;
        }
        int stars = 1;
        while(stars <= 2*i-1){
            cout<<"*";
            stars++;

        }cout<<endl;
        i++;
    }
    while(i <= n2)
    {
        int spaces = 1;
        while(spaces <= n2-i+1)
        {
            cout<<" ";
            spaces++;
        }
        int stars = 1;
        while(stars <= 2*i-1)
        {
            cout<<"*";
            stars++;
        }cout<<endl;
        i++;
    }
}