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
void deleteNode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    Node *a = temp->next;
    if(i == 0)
    {
        delete(temp);
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        a = a->next;
        count++;
    }
    if(temp != NULL && a != NULL)
    {
    temp->next = a->next;
    delete (a);
    }
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
int main()
{
    Node *head = takeInput();
    int i;
    cin >> i;
    // head = insertNode(head,i,data);
    deleteNode(head, i);
    print(head);
}