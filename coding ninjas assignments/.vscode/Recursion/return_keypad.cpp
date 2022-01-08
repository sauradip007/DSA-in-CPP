#include <iostream>
using namespace std;
int keypad(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int smaller = num % 10;
    int smallerOutput = keypad(num / 10, output);
    string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s = map[smaller];
    int k = smallerOutput;
    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = 0; j < smallerOutput; j++)
        {
            output[k] = output[j];
            k++;
        }
    }
    k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < smallerOutput; j++)
        {
            output[k] += s[i];
            k++;
        }
    }

    return k;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}