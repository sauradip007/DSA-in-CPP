#include<iostream>
#include<queue>
using namespace std;
int buyTicket(int *arr, int n, int k){
    priority_queue<int>pq;
    queue<int>q;
    for(int i = 0 ; i < n ; i++)
    {
        pq.push(arr[i]);
        q.push(i);
    }
    int i  = 0;
    int time  = 1;
    while(true)
    {
        if (pq.top() != arr[k] && q.front() != k){
            break;
        }
            if (pq.top() == arr[q.front()])
            {
                pq.pop();
                time++;
                q.pop();
            }
            else{
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
     
    }
    return time+1;
}
int main()
{
    int a[5] = {8,9,8,8,12};
    cout<<buyTicket(a,5,3)<<endl;
}