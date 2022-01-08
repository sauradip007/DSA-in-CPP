#include<iostream>
using namespace std;
#include<queue>
template<typename T>
class Node
{
public:
    T data;
    Node*next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template<typename T>
    class Queue
{
    // Define the data members
    Node<T>*head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return size == 0;
    }

    void enqueue(T data)
    {
        // Implement the enqueue() function
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

   T dequeue()
    {
        // Implement the dequeue() function
        if (head == NULL)
        {
            return -1;
        }
        Node<T> *temp = head;
        T ans = head->data;
        head = head->next;
        delete (temp);
        size--;
        return ans;
    }

   T front()
    {
        // Implement the front() function
        if (isEmpty())
        {
            return -1;
        }
        return head->data;
    }
};
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<q.size()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
        //accessing front most element and deleting it
    }
}