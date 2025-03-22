#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    char data;
    unordered_map<char, TrieNode *> childs;
    bool isTerminal;
    TrieNode(char ch)
    {
        this->data = ch;
        this->isTerminal = false;
    }
};
void insertInTrie(TrieNode *root, string str)
{
    if (str.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char charToBeAdded = str[0];
    if (root->childs.find(charToBeAdded) != root->childs.end())
    {
        // found
        insertInTrie(root->childs[charToBeAdded], str.substr(1));
    }
    else
    {
        TrieNode *nodeToBeAdded = new TrieNode(charToBeAdded);
        root->childs[charToBeAdded] = nodeToBeAdded;
        insertInTrie(root->childs[charToBeAdded], str.substr(1));
    }
}
bool searchInTrie(TrieNode *root, string str)
{
    if (str.length() == 0)
    {
        return root->isTerminal;
    }
    char charToSearch = str[0];
    if (root->childs.find(charToSearch) != root->childs.end())
    {
        // found
        return searchInTrie(root->childs[charToSearch], str.substr(1));
    }

    return false;
}
void deleteWord(TrieNode *root, string str)
{
    if (str.length() == 0)
    {
        root->isTerminal = false;
        return;
    }
    char charToSearch = str[0];
    if (root->childs.find(charToSearch) != root->childs.end())
    {

        deleteWord(root->childs[charToSearch], str.substr(1));
    }

    return;
}
int main()
{
    system("cls");
    TrieNode *root = new TrieNode('-');
    insertInTrie(root, "Abhijit");
    insertInTrie(root, "Abhishek");
    insertInTrie(root, "Abhinav");
    insertInTrie(root, "Amol");
    insertInTrie(root, "Sandeep");
    insertInTrie(root, "Suraj");
    insertInTrie(root, "Nitil");
    insertInTrie(root, "Nikhil");
    if (searchInTrie(root, "Abhijit"))
    {
        cout << "Abhijit Found" << endl;
    }
    else
    {
        cout << "Abhijit Not Found" << endl;
    }
    deleteWord(root, "Abhijit");
    if (searchInTrie(root, "Abhijit"))
    {
        cout << "Abhijit Found" << endl;
    }
    else
    {
        cout << "Abhijit Not Found" << endl;
    }
    if (searchInTrie(root, "Indrajit"))
    {
        cout << "Indrajit Found" << endl;
    }
    else
    {
        cout << "Indrajit Not Found" << endl;
    }
    return 0;
}