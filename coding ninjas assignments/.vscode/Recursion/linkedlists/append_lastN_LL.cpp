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

    count++; // small calc
    int smallOutput = length(head->next);
    return smallOutput + count;

    // considering head as 1
}
Node *lastIndex(Node *head)
{
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
Node *appendLastN(Node *head, int n)
{
    int l = length(head);
    int N = l - n;
    int count2 = 0;
    Node *p = head;
    Node *q = lastIndex(head);
    q->next = p;
    Node* temp = head;
   while(count2 < N-1)
   {
       temp = temp->next;
       
       count2++;
   }
    head = temp->next;
    q->next = p;
    temp->next = NULL;
    
   
    return head;
}
int main()
{
    Node *head = takeInput();
    int n;
    cin >> n;
    head = appendLastN(head, n);
    print(head);
}