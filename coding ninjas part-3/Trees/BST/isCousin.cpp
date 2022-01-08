#include<iostream>
#include "BinaryTreeNode.h"
#include<queue>
using namespace std;
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
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

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}
int depth(BinaryTreeNode<int>* root, int val)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->data == val)
    {
        return 0;
    }
    int leftDepth = depth(root->left,val);//depth of node is present in right subtree
    if(leftDepth != -1)
    {
        return 1 + leftDepth;
    }
    int rightDepth = depth(root->right,val);
    if(rightDepth != -1)
    {
        return 1 + rightDepth;
    }
    else{
        return -1;
    }
}
bool isSibling(BinaryTreeNode<int>* root, int p , int q)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == p || root->data == q)
    {
        return false;
    }
    if(root->left != NULL && root->right != NULL)
    {
        if(root->left->data == p && root->right->data == q)
        {
            return true;
        }
        if(root->left->data == q && root->right->data == p){
            return true;
        }
        bool a =  isSibling(root->left,p,q);
        bool b = isSibling(root->right,p,q);
        // if(a)
        // {
        //     return true;
        // }
        // if(b)
        // {
        //     return true;
        // }
        // return false;
        return a || b;
    }
    if (root->left != NULL)
    {
        return isSibling(root->left, p, q);
    }
    
        return isSibling(root->right,p,q);
    
    


    
}
bool isCousin(BinaryTreeNode<int>* root, int p , int q)
{
    return(!isSibling(root,p,q) && (depth(root->left,p) == depth(root->right,q) || depth(root->left,q) == (root->right,p)));
}
int main()
{
    BinaryTreeNode<int> *root =  takeInputLevelWise();
    cout<<isCousin(root,7,3)<<endl;

}
