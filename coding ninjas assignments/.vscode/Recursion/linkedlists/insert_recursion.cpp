#include<iostream>
using namespace std;
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
Node* insertNode(Node* head ,int i , int data)
{
    if(head == NULL)
    {
        return head; //base case
    }
    Node *newNode = new Node(data);
    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    // small calc
    Node* p = insertNode(head->next, i-1,data);
    head->next = p;
   
   
    
    // head->next = p;
    return head;
}
int main()
{
    Node* head = takeInput();
    int i,data;
    cin>>i>>data;
    head = insertNode(head,i,data);
    print(head);
}