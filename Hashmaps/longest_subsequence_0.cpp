#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int *arr, int n){
    // n^2 approach
    int s = 0;
    int max_len = 0;
    for(int i = 0; i < n ; i++)
    {
        s = 0;
        for(int j = i ; j < n ; j++)
        {
            s += arr[j];
            if(s == 0)
            {
                max_len = max(max_len, j - i + 1);
            }
        }
    }
    
    // hashmap approach
    unordered_map<int,int> freq; //key: sum val:index
    int m = 0;
    int sum = 0;
    for(int i = 1;  i <  n; i++)
    {
         arr[i-1] += arr[i];
    }
//   sum array
    for(int i = 0; i < n ; i++)
    {
        if(arr[i] == 0)//if 0 is encountered
        {
            if(m < i+1) //m is checked with the length of that subarray(basically behaves like max(m,i+1) function)
            {
                m = i+1;
            }
        }
        else if(freq.count(arr[i]) > 0) //if the sum is encountered within the array again
        {
            if(m < i - freq[arr[i]])
            {
                i = i - freq[arr[i]]; //here i -freq[arr[i]] behaves as the size using the concept if sum upto i is x and sum upto j is x then elements from index i+1 to j will sum up to 0 
            }
        }
        else{//if all the above fail simply assign the index to the sum value within the array
            freq[arr[i]] = i;

        }
    }
}