#include<iostream>
using namespace std;
int main()
{
    int n; 
    cin>>n;
    int i = 1;
    int j;
    while(i <= n )
    {
        j = i;
        while(j<= i){
            j++;
        }
        cout<<endl;
        i++;
    }
}