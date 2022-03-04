#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    vector<int> output;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < input.size(); i++)
    {
        vector<int> *p = input[i];

        for (int j = 0; j < p->size(); j++)

        {
            int t = p->at(j);
            q.push(t);
        }
    }

    while (q.size() != 0)
    {
        output.push_back(q.top());
        q.pop();
    }

    return output;
}
}