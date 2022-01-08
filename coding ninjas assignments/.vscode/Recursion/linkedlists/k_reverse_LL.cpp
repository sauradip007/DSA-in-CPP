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
    Node *smallAns = reverse(head->next);
    Node *tail = head->next; // tail is nothing but head->next 1|234 will return 432 from recursion 2 is head->next
    tail->next = head;
    head->next = NULL;
    return smallAns;
}
Node* kreverse(Node* head , int k)
{
    
    if(head == NULL || head->next == NULL || k <=1 )
    {
        return head;
    }
    int count = 0;
    
    Node *p = head;
    Node *temp = head->next;
    while(temp!= NULL&& p != NULL && count < k-1)
    {
        temp = temp->next;
        p = p->next;
        count++;
    }
    p->next = NULL;
    head = reverse(head);
    Node* newHead = kreverse(temp,k);
  
    while(p->next != NULL)
    {
        p = p->next;
       
    }
    p->next = newHead;
    return head;

  

}
int main()
{
    Node* head = takeInput();
    head = kreverse(head,2);
    print(head);
}