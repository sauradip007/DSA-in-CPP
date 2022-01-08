#include<iostream>
using namespace std;
#include<queue>
void reverse(queue<int>q)
{
    if(q.size() <= 1)
    {
        return;

    }
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++)
        {
            cin >> val;
            q.push(val);
        }

        reverse(q);
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}