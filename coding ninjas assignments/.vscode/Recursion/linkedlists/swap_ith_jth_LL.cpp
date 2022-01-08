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
Node* swapNodes(Node* head , int i , int j)
{
   if(i==0 || j==0)
   {
       if(j!=0)
       {
           int count = 0;
           Node* c1 = head;
           while(c1 != NULL && count !=j)
           {
               c1 = c1->next;
               count++;
           }
           Node* p1;
           p1->next = c1;
           head->next = c1->next;
           head =c1;
           return head;

       }
   }
   else if( i-j == 1)
   {
       if(i < j)
       {
           int count2 = 0;
           int count3 = 0;
           Node* c1 = head;
           Node *p1 = head;
           Node* c2 = head->next;
           while(c1 != NULL && count2 != i)
           {
               c1 = c1->next;
               c2= c2->next;
               count2++;
           }
           while(p1 != NULL && count3 != i-1)
           {
               p1 = p1->next;
               count3++;
           }
           
           p1->next = c1;
           c1->next = c2->next;
           c2 = p1->next;
          

       }
   }
}
Node* swaprec(Node* head , int i , int j)
{
    if(head==NULL)
    {
        return head;
    }
    if(i == j)
    {
        return head;
    }
    Node* newHead = swaprec(head,i-1,j-1);
    int count = 0;
    Node* temp = head;
    
    if(i==0)
    {
        while(temp->next != NULL && count != j-1)
        {
            temp = temp->next;
            count++;
        }
        Node* q = temp->next;
        q = head->next;
        head->next = q;
        head = q;
       
        
    return head;
        
    }
    return newHead;
}
int main()
{
    Node* head = takeInput();
    int i = 3;
    int j = 4;
    head = swaprec(head,i,j);
    print(head);
}