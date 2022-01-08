#include <iostream>
#include<cmath>
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
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL; // holds address of first node of ::, NULL indicates the LL is empty initially
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);

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

        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallAns = reverse(head->next);
    Node *tail = head->next; // tail is nothing but head->next 1|234 will return 432 from recursion 2 is head->next
    tail->next = head;
    head->next = NULL;
    return smallAns;
}
void* largest(Node* head)
{
    if(head==NULL || head->next == NULL)
    {
        return head;
    }
    int max_1 = INT_MIN;
    Node* temp = head;
    
    while( temp->next != NULL)
    {
         max_1 = max(temp->data,max_1);
        temp = temp->next;

    }
   return head;
    

}
Node* swapadj(Node* p, Node* q)
{
    Node* temp;
    temp->next = p;

    //swap p with q
    temp->next = q;
    p->next = q->next;
    q->next = p;
    return q;
   
}
Node* bubblesort(Node* head)
{
    Node* temp = head;
    //swap when NOT sorted 
    Node* c = head->next;
    //temp and c are adjacent nodes
    if (temp->data > c->data)
    {
        temp->next = c->next;
        c->next = temp;
        temp = c;
        c = temp;
    }
   
    temp = temp->next;
    c = c->next;
    while(temp!= NULL && c!= NULL)
    {
        if(temp->data > c->data)
        {
            temp = swapadj(temp,c);
        }
        temp = temp->next;
        c = c->next;

    }
    return head;

}
int main()
{
    Node* head = takeInput();
    head = bubblesort(head);
    print(head);
}