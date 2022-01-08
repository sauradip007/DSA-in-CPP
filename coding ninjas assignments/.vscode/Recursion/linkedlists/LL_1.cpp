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
Node* takeInput()
{
    int data;
    cin>>data;
    Node* head= NULL; //holds address of first node of ::, NULL indicates the LL is empty initially
    while(data != -1)
    {
        Node* newNode = new Node(data);
        
        if(head==NULL)
        {
        head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
        cin>>data;

    }
    return head;
}
void print(Node *head){
    Node* temp = head;
    while(temp!=NULL)
    {
       cout<< temp->data<<" ";
       temp=temp->next;
    }
}
int main()
{
    //Statically
    // Node n1(1);
    // Node *head = &n1; //stores address of n1 in the address of a HEAD node
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;
    // print(head);
    // cout<<n1.data<<" "<<n2.data<<endl;
    // cout<<head->data<<endl; // 1
    // cout<<head->next->data<<endl;
    //Dynamically
    // Node *n3 = new Node(10);
    // Node* n4 = new Node(20);
    // n3->next =n4;
    // Node* head2 = n3;
    Node* head = takeInput();
    print(head);
}