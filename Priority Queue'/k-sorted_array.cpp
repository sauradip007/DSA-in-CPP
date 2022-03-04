#include<iostream>
using namespace std;
#include<queue>

void kSortedArray(int input[], int n, int k)
{
    //we need a max heap
    //in cpp the default inbuilt queue is max heap
    priority_queue<int>pq;
    for(int i = 0; i < k ; i++)
    {
        //insert first k elements
        pq.push(input[i]);
    }
    int j = 0;//keeps track of which element is being placed in the sorted array
    for(int i = k ; i < n ; i++)
    {
        input[j] = pq.top();//inbuilt pq is maxx heap so topmost element will be max
        pq.pop();//remove that element
        pq.push(input[i]);//next element of unsorted array entered , it automatically gets heapified due to inbuilt function property and this process continues
        j++;
    }
    //when we come out of this loop , we get a sorted array but for n-k elements , to manage the rest of the elements we keep popping from pq
    while(!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main()
{
    int input[] = {10,12,6,7,9};
    int k = 3;
    kSortedArray(input,5,k);
    for(int i = 0; i < 5 ; i++)
    {
        cout<<input[i]<<" ";
    }
}