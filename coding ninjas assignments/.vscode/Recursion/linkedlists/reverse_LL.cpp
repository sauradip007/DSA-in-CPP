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
Node* printrev(Node* head)
{
    
    Node* curr= head;
    Node *prev = NULL;
    Node* n;
    while(curr!=NULL)
    {
         n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;

    }
    head = prev;
    return head;
}
int main()
{
    Node* head = takeInput();
    head = printrev(head);
    print(head);
}