#include<iostream>
#include "tree_node-class.h"
using namespace std;
void printPostOrder(TreeNode<int> *root)
{
    // Write your code here
    if (root != NULL)
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            printPostOrder(root->children[i]); // traverses tree from left->right->root
        }
        cout << root->data << " ";
    }
}