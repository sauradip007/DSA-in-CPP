#include<iostream>
using namespace std;

bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    // Write your code here
    //     if(root == NULL)
    //     {
    //         return false;
    //     }
    //      if(root->left == NULL && root->right != NULL)
    //     {
    //         return false;
    //     }
    //     if(root->left != NULL && root->right == NULL)
    //     {
    //         return false;
    //     }
    //     if(root->left != NULL && root->right != NULL)
    //     {
    //     if(root->left->data == p && root->right->data == q )
    //     {
    //         return false;
    //     }
    //     else if(root->left->data == p && root->right->data != q)
    //     {
    //         return isCousin(root->right,p,q);

    //     }
    //     else if(root->left->data != p && root->right->data == q)
    //     {
    //         return isCousin(root->left,p,q);
    //     }
    //     else
    //     return true;
    //     }

    //     return false;
    if (root == NULL)
    {
        return false;
    }
    if (root->data == p || root->data == q)
    {
        return false;
    }
    if (root->left->data == p || root->right->data == q)
    {
        return false;
    }
    if (root->left->data == q || root->right->data == p)
    {
        return false;
    }
    // if(root->left->data == p && root->right->data == q)
    // {
    //     return false;
    // }
    // if(root->left->data == p && root->right->data == q){
    //     return false;
    // }
    else
    {
        return true;
    }
    bool a = isCousin(root->left, p, q);
    bool b = isCousin(root->right, p, q);
    //     if(a)
    //     {
    //         return true;
    //     }

    //   if(b)
    //   {
    //       return true;
    //   }

    //     if(a || b)
    //     {
    //         return true;
    //     }

    //     return false;
    return a || b;

    // return false;
}