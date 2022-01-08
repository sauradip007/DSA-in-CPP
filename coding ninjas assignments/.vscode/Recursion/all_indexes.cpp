#include<iostream>
using namespace std;
int allIndexes(int a[], int n , int x , int output[]){
    if(n == 0)
    {
        return -1;
    }
    int ans = allIndexes(a,n-1,x,output);
    if(a[n-1] != x)
    {
        return ans;
    }
    else{
       output[ans] = a[n-1];
       return ans+1;
    }
    

}
int main()
{
    int a[5] = {5, 5, 6, 5, 6};
    int x = 8;
    int output[5];
    cout << allIndexes(a, 5, x,output) << endl;
}