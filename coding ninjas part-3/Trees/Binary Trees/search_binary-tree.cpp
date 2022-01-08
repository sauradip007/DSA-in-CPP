#include<iostream>
#include "BinaryTreenode.h"
using namespace std;
bool isPresent(BinaryTreeNode<int>* root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    bool a = isPresent(root->left, x);
    bool b = isPresent(root->right, x);
    if (a == true && b == false)
    {
        return true;
    }
    if (a == false && b == true)
        return true;
    if (a == true || b == true)
        return true;
    if (a == false && b == false)
        return false;
}