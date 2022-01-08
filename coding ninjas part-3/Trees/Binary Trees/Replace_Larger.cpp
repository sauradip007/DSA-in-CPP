#include <iostream>
#include<bits/stdc++.h>
#include <queue>
using namespace std;
int n = 0;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};




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
int replace(BinaryTreeNode<int>*root, int sum)
{
    if(root == NULL)
    {
        return sum;
    }
    sum = replace(root->right,sum);
    sum += root->data;
    root->data = sum;
    sum = replace(root->left,sum);
    return sum;

}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    replace(root, 0);
}
void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

// void reverseinorder(BinaryTreeNode<int>*root,int *arr)
// {
//     if(root == NULL)
//     {
//         return;
//     }
//     arr[n++] = root->data;
//     reverseinorder(root->left,arr);
//     reverseinorder(root->right,arr);
// }
// void replacelargersum(BinaryTreeNode<int>*root)
// {
// int* arr = new int [999999];
// int* b = new int[999999];
// reverseinorder(root,arr);
// sort(arr,arr+n);
// int i = 0;
// int j = n-1;
// while(i < j)
// {
//     if(arr[i] < arr[j])
//     {
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
//     i++;
//     j--;
// }
//  int sum = 0;
//  int m = 1;
//  int l = n-1;
// b[0] = arr[0];
// while(m <= l )
// {
//     sum = arr[m];
 
//     int k = m;
//     while(k != 0)
//     {
//     sum += arr[k-1];
//     k = k-1;
//     }
//     b[m] = sum;
//     m++;

// }
  

// for (int i = 0; i < n; i++)
// {
//     cout << b[i] << " ";
//     }cout<<endl;
    
// }
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    printLevelATNewLine(root);
  
}
