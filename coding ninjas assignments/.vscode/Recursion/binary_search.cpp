#include<iostream>
using namespace std;

int binarySearch(int input[], int s, int e, int element)
{
    int mid = (s+ e)/2;
    if(s >= e)
    {
        return -1;
    }
    if(input[mid] == element)
    {
        return mid;

    }
    if(input[mid] < element)
    {
       return binarySearch(input,mid+1,e,element);
    }
    else{
        return binarySearch(input,s,mid-1,element);


    }
    return -1;

}
int main()
{
    int a[5] = {1,2,4,5,6};
    cout<<binarySearch(a,0,4,5)<<endl;
}