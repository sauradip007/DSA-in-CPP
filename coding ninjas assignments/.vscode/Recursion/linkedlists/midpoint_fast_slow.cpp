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
Node* middle(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}