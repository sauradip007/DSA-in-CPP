#include<iostream>
#include "tree_node-class.h"
int height(TreeNode<int>*root)
{
    if(root == NULL)
    {
        return 0;
    }
    int smallAns = 0;//for root
    smallAns++;
    for(int i = 0; i < root->children.size();i++)
    {
        smallAns = height(root->children[i]);
    }
    return smallAns;
}