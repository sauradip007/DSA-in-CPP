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
Node* deleteNode(Node* head , int i)
{
    Node *temp = head;
    Node *a = temp->next;
    if(head== NULL)
    {
        return head;
    }
    if(i == 0)
    {
        head = head->next;
        delete(temp);
        return head;
    }//small calc
    Node* p = deleteNode(head->next, i-1);
    head->next = p;
    return head;

}
int main()
{
    Node* head = takeInput();
    int i;
    cin>>i;
    head = deleteNode(head,i);
    print(head);
}