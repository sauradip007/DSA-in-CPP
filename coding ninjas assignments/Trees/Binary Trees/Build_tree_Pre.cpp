#include<iostream>
#include "BinaryTreenode.h"
using namespace std;
BinaryTreeNode<int> *build(int *preorder, int *inorder, int ins, int ine, int pres, int pree)
{
    int rootpre = pres; //of preorder
    int preleftstart = pres+1;
   
    int inleftstart = ins;
    int rootIndex;//of inorder
    for(int i = 0; i < ine+1; i++)
    {
        if(inorder[i] == preorder[pres])
        {
            rootIndex = i;
            break;
        }
    }
    int inleftend = rootIndex - 1;
    int preleftend = preleftstart+ inleftend - inleftstart;
    int prerightstart = preleftend + 1;
    int prerightend = pree;
    int inrightstart = rootIndex + 1;
    int inrightend = ine;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(inorder[rootIndex]);
   root->left = build(preorder,inorder,inleftstart,inleftend,preleftstart,preleftend);
   root->right = build(preorder,inorder,inrightstart,inrightend,prerightstart,prerightend);
   return root;
}
BinaryTreeNode<int> *buildTree(int *preorder, int preLength,int *inorder,int inLength)
{
    // Write your code here
//    root->data = preorder[0];
// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[0]);
// int rootIndex;
// for(int i = 0 ; i < inLength; i++)
// {
//     if(inorder[i] == root->data)
//     {
//         rootIndex = i;
//         break;
        
//     }

// }
// int preleftstart = preorder[1];
// int inleftstart = inorder[0];
// int inleftend = rootIndex - 1;
// int preleftend = inleftend - inleftstart + preleftstart;
// int inrightstart = 
return build(preorder,inorder,0,inLength-1, 0,preLength-1);
}
int main()
{
    
}