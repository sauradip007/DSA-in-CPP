#include<iostream>
using namespace std;
void printarr(int a[])
{
    cout<<"Function : "<<sizeof(a)<<endl;

}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
    cout<<"Main : "<<sizeof(a)<<endl;
    printarr(a);
}