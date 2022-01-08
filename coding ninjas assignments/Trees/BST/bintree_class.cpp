#include<iostream>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;
    public:
    BinaryTreeNode(T data){
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
class BST{
    public:
    BinaryTreeNode<int>* root;
    public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    bool hasData(int data,BinaryTreeNode<int>* root)
    {
        if(root == NULL)
        {
            return false;
        }
        if(data == root->data)
        {
            return true;
        }
        if(data > root->data)
        {
            return hasData(data,root->right);
        }
        else{
            return hasData(data,root->left);
        }

    }
    BinaryTreeNode<int>*insert(int data,BinaryTreeNode<int>*root)
    {
        if(root == NULL)
        {
            BinaryTreeNode<int>*newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data < root->data)
        {
           root->left =  insert(data,root->left);
        }
        else{
            root->right = insert(data,root->right);
        }
        return root;

    }
    BinaryTreeNode<int>* delData(int data,BinaryTreeNode<int>*root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(data > root->data)
        {
           root->right =  delData(data,root->right);
        }else if(data < root->data)
        {
            root->left = delData(data,root->left);
        }else{
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left == NULL && root->right != NULL)
            {
                BinaryTreeNode<int>* temp = root->right;
                root->right  = NULL;
                delete root;
                return root->right;
            }
            else if(root->left != NULL && root->right == NULL)
            {
                BinaryTreeNode<int>* temp = root->left;
                root->left = NULL;
                return root->left;
            }
            else{
                BinaryTreeNode<int>* minNode = root->right;//to get right min
                while(minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = delData(rightMin,root->right);
            
            }
        }

    }
};