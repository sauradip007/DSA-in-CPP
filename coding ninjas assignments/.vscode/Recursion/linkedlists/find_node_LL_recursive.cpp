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
int findrec(Node* head, int n)
{
    if(head == NULL)
    {
        return -1;
    }
    if(head->data == n)
    {
        return 0;
    }
    int smallAns = findrec(head->next,n);
    if(smallAns == -1)
    {
        return smallAns;
    }
    else{
        return smallAns+1;
    }
    
}
int main()
{
    Node* head = takeInput();
    int n = 3;
    cout<<findrec(head,n)<<endl;

}
