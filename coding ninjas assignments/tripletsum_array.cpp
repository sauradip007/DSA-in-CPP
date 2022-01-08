#include<iostream>
using namespace std;
int triplet(int a[], int n , int key)
{
    int i = 0;
    int j =n-1;
    int count = 0;
    int k;
    while(i < j && k < j)
    {
         k = i+1;
        if(a[i] + a[j] + a[k] == key)
        {
            count++;
            
        }
        i++;
        j--;
        k++;
    }
    return count;

}
int main()
{
    int a[7]={1,2,3,4,5,6,7};
    cout<<triplet(a,7,12)<<endl;
}