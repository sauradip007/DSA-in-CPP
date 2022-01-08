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
Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergesorted(Node *h1, Node *h2)
{
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    Node *fh = NULL;
    Node *ft = NULL;
    if (h1->data < h2->data)
    {
        fh = h1;
        ft = h1;
        h1 = h1->next; // since fh is already occupying the req.d position in final LL
    }
    else
    {
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {

            ft->next = h1;
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

    if (h2 != NULL)
    {
        ft->next = h2;
    }
    if (h1 != NULL)
    {
        ft->next = h1;
    }

    return fh;
}
Node* mergeSort(Node* head)
{
    // int l = length(head);
    // Node* head1;
    // Node* head2;
    // int l1 = length(head1);
    // int l2 = length(head2);
    // if(l == 1)
    // {
    //     return head;
    // }
    // if(l1 == 1)
    // {
    //     return head1;
    // }
    // if(l2 == 1)
    // {
    //     return head2;
    // }
    // Node *mid = middle(head);
    // if(i < l/2)
    // {    
    //     head1 = mergeSort(head,i);
    //     head1 = head1->next;
    // }

    // int m = (i - (l-1)/2)-1;
    // head2 = mergeSort(mid->next,m);
    // Node* head3 = mergesorted(head1, head2);
    // return head3;
    
    int l = length(head);
    if(l == 1)
    {
        return head;
    }
    Node* m = middle(head);
    Node* p1head = head;
    Node* p2head = m->next;
    m->next = NULL;
    Node* h1 = mergeSort(p1head);
    Node* h2 = mergeSort(p2head);
    Node* newHead = mergesorted(h1,h2);
    return newHead;
    

}
int main()
{
    Node* head = takeInput();
    
    Node* mergeHead = mergeSort(head);
    print(mergeHead);
}