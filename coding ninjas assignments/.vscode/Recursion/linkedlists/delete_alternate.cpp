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
void deleteAlt(Node* head)
{
    Node* temp = head;
    Node* p = head->next;
    if(head == NULL)
    {
        return ;
    }
    while(p != NULL)
    {
        temp->next = p->next;
        p = p->next;
        temp = temp->next;
        p = p->next;
        if (p == NULL){
            temp->next = NULL;
            break;
            } // completing the LL
        if (p->next == NULL)
        {
            temp->next = NULL;
            break;
        }
    }
    
    
}
int main()
{
    Node* head = takeInput();
    deleteAlt(head);
    print(head);
}