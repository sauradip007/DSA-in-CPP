#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Stack
{
    Node *head;

    int size; // number of elements present in stack
public:
    Stack()
    {
        head = NULL;

        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        // if(head == NULL || size == 0)
        // {
        //     return true;
        // }
        // return false;
        return size == 0;
    }
    void push(int element)
    {
        Node *newNode = new Node(element);

        newNode->next = head;
        head = newNode;
        size++;
    }
    int pop()
    {
        if (isEmpty())
        {

            return -1;
        }
        int ans = head->data; // element to be deleted
        Node *temp = head;

        head = head->next;
        delete (temp);
        size--;
        return ans;
    }
    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head->data;
    }
};