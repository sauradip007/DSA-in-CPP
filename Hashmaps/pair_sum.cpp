#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int pairSum(int *arr, int n)
{
    // Write your code here
    unordered_map<int,int> freq;
    int count = 0;
    for(int i = 0 ; i < n ; i++)
    {
        freq[arr[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        int pairs = 0 - arr[i];
        if(freq.count(pairs) > 0)
        {
            count++;
        }
    }
    return count;
   
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}