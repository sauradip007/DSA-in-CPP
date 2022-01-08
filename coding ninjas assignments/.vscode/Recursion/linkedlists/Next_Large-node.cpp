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
Node *reverse(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverse(head->next);
    Node *temp = newHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return newHead;
}
Node* nextbig(Node* head)
{
    // Node *temp = head;
    // Node *p = temp->next;
    // while (p != NULL)
    // {
    //     temp = temp->next;
    //     p = p->next;
    // }
    // Node *n = NULL;
    // int d = temp->data + 1;
    // n->data = d;
    // temp->next = n;
    // n->next = NULL;
    // return head
Node* h1 = reverse(head);

if(h1->data < 9)
{
    h1->data = h1->data+1;
}
else if(h1->data  == 9)
{
    Node* temp = h1;
    while(temp  != NULL )
    {
      
        if(temp->data == 9)
        {
            if(temp->next == NULL)
            {
                Node* newNode = NULL;
                newNode->data = 1;
                temp->next = newNode;
                newNode->next = NULL;
                newNode = newNode->next;
            }
            else{
            temp->data = 0; // 0 leaves a 1 carry
            }
            
        }
        else{
            temp->data = temp->data + 1;
        }
        
        temp = temp->next;
        
    }
    
}
 Node* h2 = reverse(h1);
return h2;

















}
int main()
{
    Node* head = takeInput();
    head = nextbig(head);
    print(head);

}