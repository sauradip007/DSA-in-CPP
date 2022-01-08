#include <bits/stdc++.h>
#include <cstring>
/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
int sum = 0;
void rootLeafHelper(BinaryTreeNode<int> *root, int k, string s)
{
    if (root == NULL)
    {
        return;
    }
    sum += root->data;
    s.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == k)
        {
            for (int i = 0; i < s.length(); i++)
            {
                cout << s[i] << " ";
            }
            cout << endl;
        }
    }
    rootLeafHelper(root->left, k - root->data, s);
    rootLeafHelper(root->right, k - root->data, s);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    // ÷afPathsSumToK(root->right,k-sum);
    return rootLeafHelper(root, k, " ");
}


//mty second approach
int sum = 0;
void printHelper(BinaryTreeNode<int> *root, int k, vector<int> s)
{

    if (root == NULL)
    {
        // sum = 0;
        return;
    }
    s.push_back(root->data);
    sum += root->data;
    // s->push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == k)
        {

            for (int i = 0; i < s.size(); i++)
            {
                cout << s.at(i) << " ";
            }
            cout << endl;
        }
        else
        {
            s.pop_back();
        }
    }
    printHelper(root->left, k - sum, s);
    printHelper(root->right, k - sum, s);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int> path;
    return printHelper(root, k, path);
}