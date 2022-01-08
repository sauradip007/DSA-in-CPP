#include <iostream>
#include "tree_node-class.h"
#include <cmath>

TreeNode<int>* maxSumNode(TreeNode<int>* root)
{

    TreeNode<int>* ans = root;
    int sum;
    
    for(int i = 0; i < root->children.size(); i++)
    {
     sum = root->children[i]->data + root->data;//calculates sum of root and all its children
    }

    for(int i = 0 ; i < root->children.size(); i++)
    {
        TreeNode<int> *x = maxSumNode(root->children[i]);
        int xsum = x->data;
        for(int j = 0 ; j < x->children.size(); j++)
        {
            
            
            xsum += x->children[j]->data;
            if(xsum > sum)
            {
                sum = xsum;
                ans = x;
            }
        }
        // if (xsum > sum)
        // {
        //     sum = xsum;
        //     ans = x;
        // }
    }
    return ans;

}