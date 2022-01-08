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
    // Node* temp = head;
    // int count  = 1;
    // while(temp != NULL)
    // {
    //     temp->next;
    //     count++;
    // }

    count++; // small calc
    int smallOutput = length(head->next);
    return smallOutput + count;

    // considering head as 1
}
Node* middle( Node* head)
{
    int l = length(head);
    int count = 0;
    Node* temp = head;
    while(count < l/2)
    {
        
        temp = temp->next;
        count++;
    }
  return temp;
}
Node *printrev(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    Node *n;
    while (curr != NULL )
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    head = prev;
    return head;
}
bool checkpal(Node* head)
{
    if(head == NULL)
    {
        return false;
    }
    int l = length(head);
    Node* m = middle(head);
    Node* temp = head;
    int count  = 0;
    Node*p = printrev(m);
    while(temp != m &&  m != NULL)
    {
        if(temp->data != p->data)
        {
            return false;
        }
        p = p->next;
        temp= temp->next;
      

    }
    return true;


}

int main()
{
    Node* head = takeInput();
    cout<<checkpal(head)<<endl;
    

}