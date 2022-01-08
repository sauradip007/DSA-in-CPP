#include <iostream>
#include "BinaryTreenode.h"
using namespace std;
BinaryTreeNode<int> *buildHelper(int *postorder, int *inorder, int ins, int ine, int poss, int pose)
{
    if(ins > ine || poss > pose)
    {
        return NULL;
    }
    int rootpost = pose;
    int posleftstart = poss;
    int inleftstart = ins;
    int rootIndex;
    for(int i = ins; i < ine+1; i++)
    {
        
            if(inorder[i] == postorder[pose])
            {
                rootIndex = i;
                break;
            }
        
    }
    int inleftend = rootIndex -1;
    int posleftend =  posleftstart + inleftend - inleftstart;
    int inrightstart = rootIndex + 1;
    int inrightend = ine;
    int posrightstart = posleftend + 1;
    int posrightend = pose - 1;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[pose]);
    root->left = buildHelper(postorder,inorder,inleftstart,inleftend,posleftstart,posleftend);
    root->right = buildHelper(postorder,inorder,inrightstart,inrightend,posrightstart,posrightend);
    return root;
}