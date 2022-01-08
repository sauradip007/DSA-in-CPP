#include<iostream>
#include"./BinaryTreenode.h"
#include<cmath>
#include<queue>
using namespace std;
int minimum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return INT_MAX;//largest of an empty set is plus infinite
    }
    int leftmin = minimum(root->left);
    int rightmin = minimum(root->right);
    return min(leftmin,rightmin);
}
int maximum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    return max(maximum(root->left),maximum(root->right));
}
bool isBST(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return true;
    }
    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);
    bool output = (root->data > leftmax) && (root->data <= rightmin) && isBST(root->left) && isBST(root->right);
    return output;


}
class isBSTReturn{
    public:
    bool isBST;
    int minimum;
    int maximum;
};
isBSTReturn isBST2(BinaryTreeNode<int>*root)
{
    if(root == NULL)
    {
        isBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data,maximum, max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal = (root-> data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
}
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
bool isBST3(BinaryTreeNode<int>* root, int minimum = INT_MIN , int maximum = INT_MAX)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data < minimum || root->data > maximum)
    {
        return false;
    }
    bool isLeftOk = isBST3(root->left,minimum,root->data);
    bool isRightOk = isBST3(root->right,root->data,maximum);
    return isLeftOk && isRightOk;
}
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
//4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << isBST3(root) << endl;
    delete root;
}
