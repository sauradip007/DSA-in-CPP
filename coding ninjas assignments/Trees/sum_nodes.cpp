#include<iostream>
#include "tree_node-class.h"
int sumOfNodes(TreeNode<int>*root)
{
    int smallAns = root->data;//val of root
    for(int i = 0; i < root->children.size(); i++)
    {
        smallAns+= sumOfNodes(root->children[i]);
    }
    return smallAns;
}