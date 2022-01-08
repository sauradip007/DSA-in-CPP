#include <iostream>
#include "BinaryTreenode.h"
using namespace std;
void mirror(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    int temp;
    root->left->data = temp;
    temp = root->right->data;
    mirror(root->left);
    mirror(root->right);
}