#include<iostream>
#include<string>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode **children; //stores address of all children
    bool isTerminal; //checks whether character of a word is terminal or not
    public:
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26 ; i++)
        {
            children[i] = NULL; //initialised with null
        }
        isTerminal = false; //first char entered cannot be terminal

    }

};
class Trie{
    //we will build our trie in this class
    TrieNode * root;
    public:
    Trie(){
        root = new TrieNode('\0');//initialising the root data of trie as a null character
    }
    void insertWord(TrieNode* root,string word)
    {
        //Base case
        if(word.size() == 0){
            root->isTerminal = true; //if word ends with " " null the node is declared as terminal
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';//provides the index 
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];

        }
        else{
            // No children
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // Recursive call
        insertWord(child,word.substr(1));
    }
    void insertWord(string word){
        insertWord(root,word);
    }
    bool searchHelper(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
                return true;
            else
                return false;
        }
        int index = word[0] - 'a';
        TrieNode *child = root->children[index];
        if (root->children[index] != NULL)
        {
            return searchHelper(root->children[index], word.substr(1));
        }
        else
        {
            return false; // that word is not present in the children array
        }
    }
    bool search(string word)
    {
        // Write your code here
        return searchHelper(root, word);
    }
    void removeWordHelper(TrieNode* root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = false; // if word ends with " " null the node is declared as terminal in this case it means that the word doesnt exist here. Once a node is not terminal it means the word simply cannot exist within the trie
            return;
        }
        // Small Calculation
        TrieNode* child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            // Word not found

        }
        removeWordHelper(child,word.substr(1));
        // Function over
        // Deallocating nodes


        // Removing childnodes
        if(child->isTerminal == false)//child of the root is not terminal
        {
            for(int i = 0; i < 26 ; i++)
            {
                if(child->children[i] != NULL)
                {
                    return;
                    // check oif the children array is null which means it shouldnt have any children
                }
            }
        }
        // Once it comes out of loop it means all the children array elements are null i.e. it has no children si
        delete child;//deallocating it
        root->children[index] = NULL;
    }
    void removeWord(string word)
    {
        return removeWordHelper(root,word);
    }
};
int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    cout<<t.search("and")<<endl;
    t.removeWord("and");
    cout<<t.search("and")<<endl;

}