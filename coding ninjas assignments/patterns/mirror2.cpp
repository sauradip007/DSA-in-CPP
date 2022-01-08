#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i = 1;
    int count = 1;
    while(i<=n)
    {
        int p = i;
        int j = 1;
        while(j <= i){
            cout<<p;
            p++;
            j++;
        }

        j = i-1;
        p = 2;
        while(j >= 1)
        {
            cout<<p;
            p--;
            j--;

        }cout<<endl;
        i++;
    

    }
    
}