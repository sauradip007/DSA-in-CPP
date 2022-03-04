#include<iostream>
#include<vector>
#include<unordered_map>
using  namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{

    // unordered_map<int,int>freq;
    // for(int i = 0; i < n ; i++)
    // {
    //     freq[arr[i]]++;
    //     //index updated
    // }
    // //first element of array check if predecessor exists, if so move forward
    // //check if predecesskr exists if NO search for successors until it cant be found , that is one subsequence obtained
    // for(int i = 0; i < n ;i++)
    // {
    //     if(freq.count(arr[i-1] > 0)
    //     {
    //         continue;
    //     }
    //     else{
    //         if(freq.count(arr[i+1]) > 0)
    //         {

    //         }
    //     }
    // }
    int max_len = -1;
    // int start =  //starting index of that element
    unordered_map<int,bool>freq;
    vector<int> v;
    for(int i = 0 ; i < n ; i++)
    {
        freq[arr[i]] = true;
    }
    int len  = 0;
    int start;
    for(int i = 0; i < n ; i++)
    { 
        freq[arr[i]] = false;
        len = 0;
        int d1 = arr[i] + 1;
        int d2 = arr[i] - 1;
        if(freq.count(d1) > 0 && freq[d1] == true)
        {
            d1++;
            while(freq.count(d1) != 0)
            {
                len++;
                d1++;
                freq[d1] = false;
                
            }
        }
        else if(freq.count(d2) > 0 && freq[d2] == true)
        {
            d2--;
            while(freq.count(d2) != 0)
            {
                len++;
                d2--;
                freq[d2] = false;
                // start = d2; //lowest element in the subsequence
            }
        }
        if(len > max_len)
        {
            max_len = len;
            start = d2;
        }
    }
    int i = 0;
    while(i < len)
    {
        v.push_back(start);
        start++;
        i++;
    }
    return v;
    
}
int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
