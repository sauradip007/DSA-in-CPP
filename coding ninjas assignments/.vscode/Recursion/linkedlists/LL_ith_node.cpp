#include<iostream>
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
void printith(Node* head , int index)
{
    Node* temp = head;
    if(temp == NULL)
    {
        cout<<0;
    }
    
    int i = 0;
    while(temp != NULL && i != index)
    {
       
        temp = temp->next;
        i++;
    }
    cout<<temp->data;

}
int main()
{
    Node* head = takeInput();
    int i;
    cin>>i;
    printith(head,i);
}