#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
string uniqueChar(string str)
{
    // Write your code here

    // remove all dups n return in string
    string output;
    unordered_map<char, bool> ourmap;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (ourmap.count(str[i]) > 0)
        {
            continue; // duplicate
        }
        else
        {
            ourmap[str[i]] = true;
            output.push_back(str[i]);
        }
    }
    return output;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}