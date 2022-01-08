#include<iostream>
#include "tree_node-class.h"
using namespace std;
int numNodes(TreeNode<int>* root)
{
    int ans = 1;//corresponding to root
    int count = 0;
    for(int i = 0 ; i < root->children.size(); i++)
    {
       ans+=numNodes(root->children[i]); //caking for each child root->children[i] denotes child nodes

        
        
    }
    return ans;
}