#include<iostream>
using namespace std;
class Deque{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
    public:
    Deque(int s)
    {
        arr = new int[s];//creates array of 10 size
        // this->size = size;
        front = -1;
        rear = 0;
        size = 0;//queue size
        capacity = s;//size of array

    }
    //checks if full
    // bool isEmpty()
    // {
    //    if()

    // }
    //insert front
    void insertRear(int data)
    {
        if(size == capacity)
        {
            cout<<"-1"<<endl;
            return;
        }
        arr[rear] = data;
        rear++;
         rear = (rear + 1) % capacity;
         if(front == -1)
         {
             front = 0;
         }
         size++;
    }
    int deleteFront()
    {
        //if isEmpty
        int ans = arr[front];
        front = (front + 1 ) % 6;
        size--;
        if(size == 0)
        {
            front = -1;
            rear = 0;
        }
        return ans;

    }

};