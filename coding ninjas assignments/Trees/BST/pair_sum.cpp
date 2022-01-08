#include <iostream>
#include "BinaryTreeNode.h"
#include<queue>
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
void inordertraverse(BinaryTreeNode<int> *root, int *arr)
{
    if (root == NULL)
    {
        return;
    }
    arr[i++] = root->data;
    inordertraverse(root->left, arr);
    inordertraverse(root->right, arr);
}
void pairsum(BinaryTreeNode<int> *root, int sum)
{
    int *arr = new int[100000];
    inordertraverse(root, arr);
    // int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + i);
    // array gets sorted
    int k = 0;
    int j = i-1;
    while (k < j)
    {
        if (arr[k] + arr[j] == sum)
        {
            cout << arr[k] << " " << arr[j];
            k++;
            j--;
        }
        if (arr[k] + arr[j] > sum)
        {
            j--;
        }
        if (arr[k] + arr[j] < sum)
        {
            // cout << arr[k] << " " << arr[j];
            k++;
            // j--;
        }
        cout << endl;
    }
}
// void pairsumtraverse(int* arr, int n, BinaryTreeNode<int>* root)
// {
//     //inorder traversing and storing in array
//     if(root == NULL)
//     {
//         return;
//     }
//     for(int i  = 0; i < n ; i++)
//     {
//         arr[i] = root->data;
//     }
//     pairsumtraverse(arr,n,root->left);
//     cout<<root->data<<endl;
//     pairsumtraverse(arr,n,root->right);
//     // 5 10 6 2 3 - 1 - 1 - 1 - 1 - 1 9 - 1 - 1
// }

// void pairsum(BinaryTreeNode<int>* root, BinaryTreeNode<int>* curr, int sum)
// {
//     curr = root;              
//     if(root == NULL)
//     {
//         return ;
//     }
//     if(root->data != INT_MIN)
//     {
//         if(hasData(sum - root->data, root))
//         {
//             cout<<curr->data<<" "<<root->data;
//             root->data = INT_MIN;
            

//         }

//         pairsum(root->left,curr,sum);
//         pairsum(root->right,curr,sum);
//     }

// }
int main()
{
    BinaryTreeNode<int>* root = takeInput();
    // int *arr = new int [10000];
    int sum = 15;
    pairsum(root,15);
}