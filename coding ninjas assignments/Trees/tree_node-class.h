#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;//<T> is optional denotes children takes the same data type as the parent i.e. treenode class 
    TreeNode(T data)
    {
        this->data = data;//whatever object is being made , it sets its data
    }
};