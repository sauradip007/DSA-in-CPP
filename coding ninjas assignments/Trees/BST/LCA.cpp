#include <iostream>
#include <queue>
using namespace std;
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
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
    }
    vector<int>* left = getRootToNodePath(root->left,data);
    if(left != NULL)
    {
        left->push_back(root->data);
    }
    vector<int>* right = getRootToNodePath(root->right,data);
    if(right != NULL)
    {
        right->push_back(root->data);
    }
    else{
        return NULL;
    }

}
   
int getLCA(BinaryTreeNode<int> *root, int a, int b){
    if(root == NULL)
    {
        return -1;
    }
    if(root->data == a || root->data == b)
    {
        return root->data;
    }
   vector<int>* output1 =  getRootToNodePath(root,a);
    vector<int>* output2 = getRootToNodePath(root,b);
    int i = 0;
    int j = 0;
    int k = output1->size();
    int l = output2->size();
    vector<int>* LCA;
    while(i < k && j < l)
    {
       
        if(output1[i] != output2[j])
        {
            i++;
            j++;
        }
        else{
           LCA = output1[i];
        }
    }



}
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
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    // Write your code here
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == a && root->data == b)
    {
        return root->data;
    }
    vector<int> *n1 = getRootToNodePath(root, a);
    vector<int> *n2 = getRootToNodePath(root, b);
    int i = 0;
    int j = 0;
    while (i < n1->size() && j < n2->size() && n1[i] == n2[j])
    {
        i++;
        j++;
    }
    n1->pop_back();
    n2->pop_back();
    // lca = ;

    return n1->at(n1->size() - 1);
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}