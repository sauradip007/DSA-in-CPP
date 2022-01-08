#include <iostream>
#include<algorithm>
#include "./BinaryTreenode.h"
#include <cmath>
#include <queue>
#include <climits>

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l, r);
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX; // largest of an empty set is plus infinite
    }
    int leftmin = minimum(root->left);
    int rightmin = minimum(root->right);
    return min(root->data, min(leftmin, rightmin));
}
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    // int min = -1;
    // int max = 1;
    if (root == NULL)
    {
        return 1;
    }
    if (isBST(root))
    {
        return height(root);
    }
    int l = largestBSTSubtree(root->left);
    int r = largestBSTSubtree(root->right);
    return max(l, r);
}