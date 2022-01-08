#include <iostream>
#include <cmath>
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
Node *evenAfterOdd(Node *head){
    Node* oddH = NULL;
    Node* oddT = NULL;
    Node* evenH = NULL;
    Node* evenT = NULL;
    Node* temp = head;
 
    while(temp!= NULL)
    {
        if(temp->data % 2 == 0)
        {
            if(evenH==NULL)
            {
                evenH = temp;
                evenT = temp;
            }
            else{
                evenT->next = temp;
                evenT = evenT->next;
                
            }
        }

        else{
            if(oddH == NULL)
            {
                oddH = temp;
                oddT = temp;
            }
            else{
                oddT->next = temp;
                oddT = oddT->next;
                
            }
        }
        temp = temp->next;
    }
    if (evenH != NULL && evenT != NULL && oddH == NULL)
    {
        oddH = evenH;
        evenT->next = NULL;
        evenT = evenT->next;
    }
        if (evenH != NULL && evenT != NULL)
        {
            evenT->next = NULL;
            evenT = evenT->next;
        }
    if(oddH != NULL && oddT != NULL)
    {
    oddT->next = NULL;
    oddT->next = evenH;
    }

    return oddH;
}
int main()
{
    Node* head = takeInput();
    head = evenAfterOdd(head);
    print(head);
}