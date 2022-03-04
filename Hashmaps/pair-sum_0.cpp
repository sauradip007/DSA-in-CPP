
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// int pairSum(int *arr, int n)
// {
//     // Write your code here
//     unordered_map<int, int> freq;
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         freq[arr[i]]++;
//     }
//     int num = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int pairs = - arr[i];
//         if (freq.count(pairs) > 0)
//         {

//             // int num = freq[arr[i]] * freq[pairs];
           
//             num++;
//             count += num;
//             // freq[pairs] = 0;
//             // freq[arr[i]] = 0;
//         }
//         else
//         {
//             continue;
//         }
//     }
//     return count;
// }

//     int main()
//     {
//         int n;
//         cin >> n;

//         int *arr = new int[n];

//         for (int i = 0; i < n; ++i)
//         {
//             cin >> arr[i];
//         }

//         cout << pairSum(arr, n);

//         delete[] arr;
    // }
unordered_map<int, int> map;
int cnt = 0;
for(int i = 0; i < n; i++)
{
    int key = 0 - arr[i];

    if (map[key] > 0)
        cnt = cnt + map[key];

    else
    continue;
}
return cnt;
}
// int pairSum(int *arr, int n)
// {
//     unordered_map<int, int> mp;
//     int negative;
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         negative = -arr[i];
//         if (mp.find(negative) != mp.end())
//         {
//             count += mp[negative];
//         }
//         mp[arr[i]]++;
//     }
//     return count;
// }
