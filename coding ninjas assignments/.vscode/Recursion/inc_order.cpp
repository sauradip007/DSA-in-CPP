#include<iostream>
using namespace std;
void print(int n)
{
    if(n==1)
    {
        cout<<n;
    }
    cout<<n<<" "<<endl;
    print(n-1);
}
int main()
{
    int n;
    cin>>n;
    print(n);
}