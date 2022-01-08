#include <iostream>
#include "BinaryTreenode.h"
#include<queue>
using namespace std;
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


pair<int, int> getMinAndMax(BinaryTreeNode<int> *root){
    if(root == NULL)
    {
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        //min and max is 0
        return p;
    }
    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);
    int lmax = leftAns.first;
    int lmin = leftAns.second;
    int rmax = rightAns.first;
    int rmin = rightAns.second;
    //overall
    int maximum = max(lmax,rmax,max(lmin,rmin));
    int minimum = min(lmin,rmin,min(lmax,rmax));
    pair<int, int> p;
    p.first = maximum;
    p.second = minimum;
    return p;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}