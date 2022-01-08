#include <iostream>
#include "tree_node-class.h"
#include<queue>
using namespace std;
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printLevelATNewLine(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode<int> *first = q.front();
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
        for (int i = 0; i < first->children.size(); i++)
        {
            q.push(first->children[i]);
        }
    }
}
void replaceWithDepth(TreeNode<int> *root, int k)
{
    // k = 0;
    // if(k == 0)
    // {
    //     root->data = k;
    //     cout<<root->data;
    // }
    if (root == NULL)
    {
        return;
    }
    // if (k == 0)
    // {
    //     root->data = 0;
    // }
    root->data = k;
    // cout<<root->data<<" ";
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepth(root->children[i], k + 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    replaceWithDepth(root,0);
    printLevelATNewLine(root);
}