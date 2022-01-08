#include<iostream>
using namespace std;
bool is_sorted(int a[], int size)
{
    if (size <= 1)
    {
        return true;
    }
    bool isSmallerOutput = is_sorted(a+1, size-1);
    // alternate approach , call recursion for smaller array first then compare w first index
    if(!isSmallerOutput)
    {
        return false;
    }
    if(a[0] > a[1])
    {
        return false;
    }
    else{
        return true;
    }
}

bool isSorted(int a[], int size)
{
    if(size<=1)
    {
        return true;
    }
    if(a[0] > a[1]){
        return false;
    }
    bool isSmallerSorted = isSorted(a+1, size-1);
    return isSmallerSorted;
    // if(isSmallerSorted){
    //     return true;
    // }else{
    //     return false;
    // }
}
int main()
{

}