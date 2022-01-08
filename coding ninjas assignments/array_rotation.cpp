#include<iostream>
using namespace std;
void rotate(int a[], int d, int n)
{
    
    int b[d];
    for(int j = 0; j < d ; j++)
    {
        b[j] = a[j];
    }
    for(int i = d ; i < n ; i++)
    {
       a[i-d] = a[i];

    }
 for(int k = 0; k < d ; k++)
 {
     a[n-d+k] = b[k];
 }
}
int main(){
    int a[7] = {1,2,3,4,5,6,7};
    rotate(a,2,7);
    for(int i = 0; i < 7 ;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;

}