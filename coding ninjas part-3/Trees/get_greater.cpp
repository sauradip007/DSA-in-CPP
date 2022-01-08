#include <iostream>
#include "tree_node-class.h"
#include <cmath>
int getGreater(TreeNode<int>* root, int x)
{
    if(root == NULL)
    {
        return NULL;

    }
    int count = 0;
    if(root->data > x)
    {
        count++;
        
    }


    for(int i  = 0; i < root->children.size(); i++)
    {
       count += getGreater(root->children[i],x);

    }
    return count;
}