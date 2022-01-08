#include<iostream>
#include "tree_node-class.h"
#include<queue>
using namespace std;
// TreeNode<int>* takeInputLevelWise(){
//     int rootData;
//     cout << "Enter root data" << endl;
//     cin >> rootData;
//     TreeNode<int> *root = new TreeNode<int>(rootData);//root node made
//     queue<TreeNode<int>*> pendingNodes;
//     pendingNodes.push(root);//root is pushed first
//     while(pendingNodes.size() != 0)
//     {
//         TreeNode<int>* front = pendingNodes.front();
//         pendingNodes.pop();
//         cout<<"Enter num of children of front "<<front->data<<endl;
//         int numChild;
//         cin>>numChild;
//         for(int i = 0; i < numChild; i++)
//         {
//             int childData;
//             cout<<"Enter "<<i<< "th child of "<<front->data<<endl;
//             TreeNode<int>*child = new TreeNode<int>(childData);//statically allocating child nodes
//             front->children.push_back(child); //making the linkage
//             pendingNodes.push(child);
//         }
//     }
//     return root;
    
// }

    TreeNode<int>* takeInputLevelWise(){
        int rootData;
        cout << "Enter root data" << endl;
        cin >> rootData;
        TreeNode<int> *root = new TreeNode<int>(rootData); // root node made
        queue<TreeNode<int>*>pendingNodes;
        pendingNodes.push(root);//first enter root data
        while(!pendingNodes.empty())
        {
            TreeNode<int>*front = pendingNodes.front();
            //front node is taken out to make linkages
             //then its popped
             pendingNodes.pop();
             cout<<"Enter num of children of " <<front->data<<endl;
             int numChild; //no of children
             cin>>numChild;
             for(int i = 0; i < numChild; i++)
             {
                 int childData;
                 cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
                 cin>>childData;
                 TreeNode<int> *child = new TreeNode<int>(childData);
                 front->children.push_back(child);
                 pendingNodes.push(child);
             }
            

             

        }

return root;
}

void printLevelWise(TreeNode<int>*root)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();//stores node
        pendingNodes.pop(); //gets out of queue
        cout<<front->data<<" : ";
        for(int i = 0; i < front->children.size(); i++)
        {
           
            cout<<front->children[i]->data<<" , ";
            pendingNodes.push(front->children[i]);
        }
        
    }


}

//correct code
void printLevelWise(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop(); // gets out of queue
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " , ";
        }
    }
}

    // TreeNode<int>* takeInput()
    // {
    //     int rootData;
    //     cout<<"Enter data"<<endl;
    //     cin>>rootData;
    //     TreeNode<int> *root = new TreeNode<int>(rootData);
    //     int n;//denotes no of children
    //     cout<<"Enter number of children of root data entered : "<<endl;
    //     cin>>n;
    //     for(int i = 0 ; i < n; i++)
    //     {
    //         TreeNode<int>*child = takeInput();//takeinput will be called for each child node
    //         root->children.push_back(child);//makes the linkage between the data
    //     }
    //     return root;
    // }
    void printTree(TreeNode<int> *root)
{

    //Recursive function base case gets automatically handled
    //this is the edge case NOT base case when argument entered is a NULL pointer
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" : ";
    for(int i = 0; i < root->children.size(); i++)
    {
        cout<<root->children[i]->data<<" , ";
    } //prints data of each node ,loop is run for each child
    cout<<endl;
    for(int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }//goes to child node which behaves as the root,checks for more children. Root node is printed with a : with child nodes followed by a ','
}
int main()
{
    // TreeNode<int>* root = new TreeNode<int>(1); //root
    // TreeNode<int> *node1= new TreeNode<int>(2);//these are objects 
    // TreeNode<int> *node2= new TreeNode<int>(3);//objects
    //right now tree is looking like this
    //            1
    //        2       3
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    
}