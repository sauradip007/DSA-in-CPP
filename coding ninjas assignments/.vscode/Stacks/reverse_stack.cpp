#include<iostream>
#include<stack>
using namespace std;
void reversestack(stack<int>a,stack<int>b)
{
    stack<int> c; //another helper stack
    while(!a.empty())
    {
        b.push(a.top());
        a.pop();

    }
    while(!b.empty())
    {
        c.push(b.top());
        b.pop();
    }
    while(!c.empty())
    {
        a.push(c.top());
        c.pop();
    }

}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reversestack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}