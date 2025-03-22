#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
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
void storeSuggestion(TrieNode *root, vector<string> &suggstions, string &start)
{
    if (root->isTerminal || root->childs.size() == 0)
    {
        suggstions.push_back(start);
    }

    for (auto each : root->childs)
    {

        cout << "_" << each.first << endl;
        start.push_back(each.first);
        storeSuggestion(each.second, suggstions, start);
        start.pop_back();
    }
}

void findSuggestions(TrieNode *root, string prefix, vector<string> &suggstions, string &start)
{
    if (prefix.length() == 0)
    {
        // store ans;
        storeSuggestion(root, suggstions, start);
        return;
    }
    char ch = prefix[0];
    if (root->childs.find(ch) != root->childs.end())
    {
        findSuggestions(root->childs[ch], prefix.substr(1), suggstions, start);
    }
}
int main()
{
    system("cls");
    TrieNode *root = new TrieNode('-');
    insertInTrie(root, "Abhijit");
    insertInTrie(root, "Abhishek");
    insertInTrie(root, "Abhi");
    insertInTrie(root, "Abhinav");
    insertInTrie(root, "Amol");
    insertInTrie(root, "Sandeep");
    insertInTrie(root, "Suraj");
    insertInTrie(root, "Nitil");
    insertInTrie(root, "Nikhil");

    string prefix = "Ab";
    string ans = prefix;
    vector<string> suggestions;
    findSuggestions(root, prefix, suggestions, ans);
    for (string el : suggestions)
    {
        cout << el << endl;
    }
    return 0;
}