#include <iostream>

#include "BinaryTreeNode.h"
#include<queue>
#include <cmath>
#include<vector>
using namespace std;
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
    queue<BinaryTreeNode<int> *> pendingNodes; // queue that holds nodes
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // now ask for left child
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
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data)
{
    //base
    if(root == NULL)
    {
        return NULL;
}

    if(root->data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;

    }
    vector<int>* leftOutput = getRootToNodePath(root->left,data); //trying for left
    if(leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput = getRootToNodePath(root->right,data);
    if(rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
}
int main()
{
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInputLevelWise();
    vector<int>* output = getRootToNodePath(root,8);
    for(int i = 0 ; i < output->size(); i++)
    {
        cout<<output->at(i)<<endl;
    }
    delete output;
}