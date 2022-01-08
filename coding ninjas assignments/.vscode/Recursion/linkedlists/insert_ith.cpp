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
Node* insertNode(Node* head , int i, int data)
{
    Node* newNode = new Node(data);
    int count = 0;
    Node* temp = head;
    if(i==0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp!= NULL && count < i-1)
    {
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
    newNode->next = temp->next;
    temp->next = newNode;
    }
    return head;
}
Node* deleteNode(Node* head, int i)
{
    int count = 0;
    Node* temp = head;
    Node* a = temp->next;
    if(i == 0)
    {
      head = head->next;
      delete(temp);
     return head;
        }
    while(temp != NULL && count < i-1)
    {
        temp = temp->next;
        a = a->next;
        count++;
    }
    if(temp != NULL)
    {
    temp->next = a->next;
    
    }
    delete (a);
    return head;
}
int main()
{
    Node* head = takeInput();
    int i;
    int data;
    cin>>i;
    // head = insertNode(head,i,data);
    head = deleteNode(head,i);
    print(head);
}