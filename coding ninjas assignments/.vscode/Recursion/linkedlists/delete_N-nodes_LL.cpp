#include <iostream>
#include <cmath>
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
int length(Node *head)
{
    int count = 0;
    if (head == NULL)
    {

        return count;
    } // base call
    // Node* temp = head;
    // int count  = 1;
    // while(temp != NULL)
    // {
    //     temp->next;
    //     count++;
    // }

    count++; // small calc
    int smallOutput = length(head->next);
    return smallOutput + count;

    // considering head as 1
}
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
Node *deleteN(Node *head, int m, int n)
{
    // if(head == NULL || head->next==NULL || m == 0)
    // {
    //     return head;
    // }
    int l = length(head);
    // Node* temp = head;
    // // Node* p = head->next;

    // while(temp != NULL && c1 != m)
    // {
    //     temp = temp->next;
    //     c1++;

    // }
    // //reached m
    // Node * p;
    // Node *q;
    // if(temp != NULL)
    // {
    // temp->next = p;

    // q = p->next;
    // }
    // while(p!= NULL && c2 != n)
    // {
    //     p=p->next;
    //     q=q->next;
    //     c2++;
    // }
   
    Node *t1 = head;
    Node *t2 = NULL;
   
    while (t1 != NULL )
    {
        int c1 = 1, c2 = 1;
        while (t1 != NULL && c1 != m)
        {
            t1 = t1->next;
            c1++;
        }
        // node has traversed m spaces
      
        t2 = t1->next;
        while (t2 != NULL && c2 != n)
        {
            t2 = t2->next;
            c2++;
        }
        // t2 traversed n spaces
        if (t2 != NULL)
        {
            t2 = t2->next; // moving t2 to the place of connection to be made by t1
            t1->next = t2; // making the connection
            t1 = t1->next; // moving t1 in the place of t2 for the next traversal
        }
        // count reset to 1
        else{
            t1->next = NULL;
            t1 = t1->next;
        }
    }
   
    return head;
}
int main()
{
    Node *head = takeInput();
    head = deleteN(head, 2, 2);
    print(head);
}