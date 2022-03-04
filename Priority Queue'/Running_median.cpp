#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdlib>
using namespace std;
int median(int* arr, int n)
{
    priority_queue<int, vector<int>, greater<int>> p;
    //min-heap
    priority_queue<int>q;
    //max-heap

int med; 
med = arr[0];
if(med != 0)
{
    cout<<med<<" ";
}

q.push(arr[0]); //pushing first elem of array into max heap
int minsize = p.size(); // size of min heap
int maxsize = q.size(); //size of max heap
for(int i = 1; i < n; i++)
{
    // 3 cases when they are greater lesser and equal
    // case-1 max greater than min
    if(maxsize > minsize)
    {
        if(maxsize - minsize <= 1)
        {
            if (arr[i] > q.top())
                {
                    p.push(arr[i]); //pushing into second half i.e. min heap with greater elements
                }
                if(arr[i] < q.top())
                {
                    q.push(arr[i]); //pushing to max heap i.e. first half with lesser elements
                }
        }
        else{
            int y = q.top();
            q.pop();
            p.push(y);
        }
        med = q.top(); // top of minheap
    }
    else if(maxsize < minsize)
    {
        if (minsize - maxsize <= 1)
        {
            if (arr[i] > q.top())
            {
                p.push(arr[i]); // pushing into second half i.e. min heap with greater elements
            }
        if (arr[i] < q.top())
        {
            q.push(arr[i]); // pushing to max heap i.e. first half with lesser elements
        }
        }
        else{
            int x = p.top();
            p.pop();
            q.push(x);
        }
        med = p.top();
    }
    else{
        med = (p.top() + q.top())/2;
    }

    cout<<med<<" ";
}















    // if(abs(minsize - maxsize) <= 1) //absolute difference of max and min heap sizes should either be 0 or 1
    // {
    //     if(arr[i] >  q.top())
    //     {
    //         p.push(arr[i]); //pushing into second half i.e. min heap with greater elements
    //     }
    //     if(arr[i] < q.top())
    //     {
    //         q.push(arr[i]); //pushing to max heap i.e. first half with lesser elements
    //     }
    // }
    // else{ //shuffling and balancing both the heaps
    //     if(minsize > maxsize)
    //     {
    //         int x = p.top();
    //         p.pop();
    //         q.push(x);
    //     }
    //      if(maxsize > minsize)
    //     {
    //         int y = q.top();
    //         q.pop();
    //         p.push(y);
    //     }
       
    





    if(maxsize > minsize)
    {
        // int x = q.top();
        // q.pop();
        med = q.top(); //top of maxheap
    }
    else if(maxsize < minsize)
    {
        med = p.top(); //top of minheap
    }
    else
    {
        med = (p.top() + q.top()) / 2; //even size
    }
    cout<<med<<" ";
}









    // int med;
    // med = arr[0];
    // if(med != 0)
    // {
    //     cout<<med<<" ";
    // }
    // q.push(arr[0]);
    // for(int i = 1 ; i < n ; i++)
    // {
    //     //first half and second half
    //     if(p.size() - q.size() <= 1 || q.size() - p.size() <= 1)
    //     {
    //         if(arr[i] < q.top())
    //         {
    //             q.push(arr[i]);
    //         }
    //         else{
    //             p.push(arr[i]);
    //         }

    //     }
    //     else{
    //         if(p.size() > q.size())
    //         {
    //             int x = p.top();
    //             q.push(x);
    //             p.pop();
    //         }
    //         else if(p.size() < q.size()){
    //             int y = q.top();
    //             p.push(y);
    //             q.pop();

    //         }
    //     }
    //     if(p.size() > q.size())
    //     {
    //         med = p.top();
    //     }
    //     else if(p.size() < q.size())
    //     {
    //         med = q.top();
    //     }
    //     else{
    //         med = (p.top() + q.top()) / 2;
    //     }
    //     cout<<med<<" ";
    // }cout<<endl;

    // // My approach
    // priority_queue<int, vector<int>, greater<int>> p;
    // // min-heap
    // priority_queue<int> q;
    // // max-heap
    // int med;
    // med = arr[0];
    // if (med != 0)
    // {
    //     cout << med << " ";
    // }
    // q.push(arr[0]);
    // for (int i = 1; i < n; i++)
    // {
    //     // max heap q greater than min heap p
    //     if(q.size() > p.size())
    //     {
    //         if(q.size() - p.size() == 1 || q.size() - p.size() == 0)
    //         {
    //             if (arr[i] < q.top())
    //             {
    //                 q.push(arr[i]);
    //             }
    //             else
    //             {
    //                 p.push(arr[i]);
    //             }
    //         }
    //         else{
    //             int y = q.top();
    //             p.push(y);
    //             q.pop();
    //         }
    //     }
    // }
}
int main()
{
        int a[6] = {6,2,1,3,7,5};
        // findMedian(a,6);
        // for(int i = 0 ; i < 6 ; i ++)
        // {
        //     cout << a[i] << " ";
        // }
}