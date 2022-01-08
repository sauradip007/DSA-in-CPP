#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *takeInput()
{
    int data;
    cin>>data;
    Node* head = NULL; //indicates LL is empty
     //address of n is stored

    while(data != NULL)
    {
        Node* newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;//head is updated to first node(thats it)
        }
        else{
            // head->next = newNode;
            Node* temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;//taking temp to the last node and updating its val with address of next node
        }
        cin>>data;
    }
}