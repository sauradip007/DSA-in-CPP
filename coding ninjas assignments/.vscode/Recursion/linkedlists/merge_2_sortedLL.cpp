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
Node* mergesorted(Node* h1, Node* h2)
{
    if(h1 == NULL)
    {
        return h2;
    }
    if(h2 == NULL)
    {
        return h1;
    }
    Node* fh = NULL;
    Node* ft = NULL;
    if(h1->data < h2->data)
    {
        fh = h1;
        ft = h1;
        h1 = h1->next; //since fh is already occupying the req.d position in final LL
    }
    else{
        fh=h2;
        ft = h2;
        h2 = h2->next;
    }
    while(h1 != NULL && h2 != NULL)
    {
        if(h1->data < h2->data)
        {
          
            ft->next= h1;
            h1 = h1->next;
            ft = ft->next;
        }
        else 
        {
            
            ft->next = h2;
            h2 = h2->next;
            ft = ft->next;
        }
    }
   
    if(h2 != NULL)
    {
        ft->next = h2;
     

    }
    if(h1 != NULL)
    {
        ft->next = h1;
     
    }
    
    return fh;
}
int main()
{
    Node* h1 = takeInput();
    Node* h2 = takeInput();
    Node* fh  = mergesorted(h1,h2);
    print(fh);
}