#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// int n = 0;
// void inorder(BinaryTreeNode<int> *root, int *arr)
// {
//     if (root == NULL)
//         return;

//     arr[n++] = root->data;
//     inorder(root->left, arr);
//     inorder(root->right, arr);
// }

// void pairSum(BinaryTreeNode<int> *root, int num)
// {
//     int *arr = new int[1999999];
//     // int  n=i;
//     inorder(root, arr);
//     sort(arr, arr + n);

//     int i = 0;
//     int j = n - 1;
//     while (i < j)
//     {
//         if (arr[i] + arr[j] > num)
//         {
//             j--;
//         }
//         else if (arr[i] + arr[j] < num)
//         {
//             i++;
//         }
//         else if (arr[i] + arr[j] == num)
//         {

//             cout << arr[i] << " " << arr[j] << endl;
//             j--;
//             i++;
//         }
//     }
// }
int i = 0;

bool hasData(int data, BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return hasData(data, root->left);
    }
    else
    {
        return hasData(data, root->right);
    }
}

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
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void pairSumHelper(BinaryTreeNode<int>*root,int num)
{
    
}