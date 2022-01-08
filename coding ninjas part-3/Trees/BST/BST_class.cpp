#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;
class BST{
    BinaryTreeNode<int>* root;
    public:
    BST(){
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    private:
    bool hasData(int data, BinaryTreeNode<int>* root)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return hasData(data,root->left);
        }
        else{
            return hasData(data,root->right);
        }
    }
    bool search(int data){
     return hasData(data,root);
       
        }//looks if data is present or not

    
    BinaryTreeNode<int>* delData(BinaryTreeNode<int>*root, int data){
        if(root == NULL)
        {
            return NULL;//nothing to delete
        }
        if (root->data > data)
        {
            root->left = delData(root->left, data);
        }
        if (root->data < data)
        {
            root->right = delData(root->right, data);
        }
       else
        {
            if(root->left == NULL && root->right == NULL)
            {
                delete root; //actually deleting
                return NULL;
            }
           else if(root->left == NULL)
            {
               BinaryTreeNode<int>* temp = root->right;
               root->right = NULL;
                
                delete root; //actually deleting from memory
                return temp;
            }
            else if(root->right == NULL)
            {
                BinaryTreeNode<int>* tmp = root->left;
                root->left = NULL;
                delete root;
                return tmp;
            }
            else{
                BinaryTreeNode<int>* minNode = root->right;
                while(minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                // BinaryTreeNode<int>* maxNode = root->left;
                // while(maxNode->right != NULL)
                // {
                //     maxNode = maxNode->right;
                // }
                // int leftMax = maxNode->data;
                // root->data = 
                root->right = delData(root->right,rightMin);
                return root;
            }
        }
    }
    void deleteData(BinaryTreeNode<int>*root,int data)
    {
        root = delData(root,data);

    }

    BinaryTreeNode<int>* insertData(BinaryTreeNode<int>*root, int data)
    {
        if(root == NULL)
        {
            BinaryTreeNode<int>*newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (root->data > data)
        {

             root->left= insertData(root->left,data);
            
            
        }
        else{
            root->right = insertData(root->right,data);
        }
        return root;
    }
    

    void insert(BinaryTreeNode<int>*root,int data){
        // if(root == NULL)
        // {
        //     BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
        //     return;//inserted data will behave as the root data
        // }
        // if(root->data > data)
        // {
            
        //     insert(root->left,data);
        //     root = root->left;
        //     return;
        // }
        // if(root->data < data)
        // {
           
        //     insert(root->right,data);
        //     root = root->right;
        //     return;
        // }
        this->root = insertData(this->root,data);

    }
   

};