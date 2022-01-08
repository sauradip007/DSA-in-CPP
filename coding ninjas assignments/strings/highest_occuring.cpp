#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    string s;

    int maxCount = INT_MIN;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        int count = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[i] == s[j])
            {
                count++;
                maxCount = max(maxCount, count);
            }
            
        }
    }