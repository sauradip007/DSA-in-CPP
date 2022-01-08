#include <iostream>
#include "tree_node-class.h"
using namespace std;
TreeNode<int>* nextlarge(TreeNode<int>* root, int x)
{
    if(root == NULL)
    {
        return NULL;
    }
    TreeNode<int>* ans = root;
    if(root->data > x)
    {
        return ans;

    }



    for(int i = 0 ;i < root->children.size();i++)
    {
        TreeNode<int>* y = nextlarge(root->children[i],x);
        if(y->data > ans->data)
        {
            ans = y;
            break;
        }
     
    }
    return ans;
}