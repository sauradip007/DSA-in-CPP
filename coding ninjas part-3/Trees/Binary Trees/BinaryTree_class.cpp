#include<iostream>
#include<queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
void printTree(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
   
    }//explicitly mentioning
    if(root->right != NULL)
    {
        cout<<"R"<<root->right->data;
    }cout<<endl;
    printTree(root->left);
    printTree(root->right);
    //preorder
}
BinaryTreeNode<int>*takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes; //queue that holds nodes
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        //now ask for left child
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;

}
void printLevelWise(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left)
        {
            cout<<"L:"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if (front->right)
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
        // BinaryTreeNode<int>* child = new BinaryTreeNode<int>()
    }
}
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    //called and node created for left and right children then the linage is made
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void inorder(BinaryTreeNode<int>*root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;
    BinaryTreeNode<int>* root = takeInputLevelWise();
    // printLevelWise(root);
    inorder(root);
    delete root;
 
}