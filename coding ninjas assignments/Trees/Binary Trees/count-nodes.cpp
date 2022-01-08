#include<iostream>

using namespace std;
template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

int count(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    int l = count(root->left);
    int r = count(root->right);
    return l + r +1 ;
}