#include<iostream>
#include "tree_node-class.h"
#include <cmath>
int maxNode(TreeNode<int>* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    int m;
    int smallAns = -1;

    m = root->data;
    TreeNode<int> *ans = root; //= new TreeNode<int>(smallAns);

    /*  if(root->data > smallAns)
      {
          smallAns =m;
          ans->data = m;
          return ans;

      }*/

    // smallAns = root->data;
    // ans->data = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = maxDataNode(root->children[i]);
        if (ans->data < temp->data)
            ans = temp;
    }
    return ans;
}