#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    // base
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left, data); // trying for left
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}
int  getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    if(root == NULL)
    {
        return 0;
    }
    vector<int>* n1 = getRootToNodePath(root,a);
    vector<int>* n2 = getRootToNodePath(root,b);
    
  int lca;
    // if(n1->size() > n2->size())
    // {
    //     n = n1->size();
    // }
    // else{
    //     n = n2->size();
    // }
    // for(int i = 0 ; i < n ; i++)
    // {
        
    //     if(n1[i] == n2[i])
    //     {
    //         c1 = 0;
    //         c2 = 0;
    //     }
    //     else{
    //         c1++;
    //         c2++;
            
    //     }
    //     if (c1 == c2)
    //     {
    //         lca = c1;
            
    //     }
    // }
    int i = 0; int  j = 0;
    // while( i < n1->size() && j < n2->size())
    // {
    //     // if(n1[i] == n2[j])
    //     // {
    //     //     c2 = 0;
    //     //     c1 = 0;
    //     // }
    //     // else{
    //     //     c1++;
    //     //     c2++;
    //     // }
    //    if(n1[i] != n2[j])
    //    {
    //        i--;
    //        j--;
    //       lca = n1.at(i);
    //       break;
    //    }
      
    //     i++;
    //     j++;
    // }

    while(i < n1->size() && j < n2->size() && n1[i] == n2[j])
    {
        i++;
        j++;

    }
    n1->pop_back();
    n2->pop_back();
    // lca = ;

    return n1->at(n1->size()-1);
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
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == a || root->data == b)
    {
        return root->data;
    }
    int n1 = getLCA(root->left, a, b);
    // Write your code here);
    int n2 = getLCA(root->right, a, b);
    // Write your code here);
    if (n1 != -1 && n2 != -1)
    {
        return root->data;
    }
    if (n1 == -1 && n2 != -1)
    {
        return n2;
    }
    if (n1 != -1 && n2 == -1)
    {
        return n1;
    }
}
    int main()
    {
        BinaryTreeNode<int> *root = takeInputLevelWise();
        cout << getLCA(root, 4, 5) << endl;
    }