#include <iostream>
#include "BinaryTreenode.h"
#include <queue>
using namespace std;
BinaryTreeNode<int> *removeleaf(BinaryTreeNode<int> *root)
{
    // BinaryTreeNode<int>* prev = NULL;

    // if(root == NULL)
    // {
    //     return NULL;
    // }
    // BinaryTreeNode<int>* ans = root;
    // if(ans->left == NULL && ans->right == NULL)
    // {
    //     delete(ans);
    // }
    // ans = removeleaf(root->left);
    // ans = removeleaf(root->right);
    // return ans;
    BinaryTreeNode<int>* ans = root;
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->left == NULL)
    {
        delete(root);
        ans->right = NULL;
        ans->left = NULL;

    }
    ans = removeleaf(root->right);
    ans = removeleaf(root->right);
    return ans;


}