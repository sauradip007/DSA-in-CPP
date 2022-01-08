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
//creating a class with head and tail so both parameters can be returned by reverse LL func to optimise time complexity
class Pair{
    public:
    Node* head;
    Node* tail;
};
Node* reverseLL3(Node* head)
{
    if(head==NULL || head->next == NULL)
    {
        return head;
    }
    Node* smallAns = reverseLL3(head->next);
    Node* tail = head->next; //tail is nothing but head->next 1|234 will return 432 from recursion 2 is head->next 
    tail->next = head;
    head->next = NULL;
    return smallAns;

}
Pair reverseLL(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head; //corresponding to head->next == NULL i.e. when its of length 1 the head and tail will be the same for its reverse
        ans.tail = head;
        return ans;
        //for head== NULL , NULL will be returned so no code for it

    }

   
    Pair newHead = reverseLL(head->next);
    newHead.tail->next = head;
    head->next = NULL;
    Pair ans; //final ans
    ans.head = newHead.head;//always important to store these variables in another object to prevent errors
    ans.tail = head;
    return ans;
 
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
Node *reverse(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *h1 = head->next;
    Node *newHead = reverse(h1);
    Node *temp = newHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return newHead;
}
Node* reverseLL_better(Node* head)
{
    return reverseLL(head).head;
}
int main()
{
    Node* head = takeInput();
    head = reverseLL3(head);
    print(head);
}