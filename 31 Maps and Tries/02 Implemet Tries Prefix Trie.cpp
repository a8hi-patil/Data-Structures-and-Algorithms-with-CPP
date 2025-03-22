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
class Trie
{
    TrieNode *root = nullptr;

public:
    Trie() { this->root = new TrieNode('-'); }
    void insertHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        char charToBeAdded = word[0];
        if (root->childs.find(charToBeAdded) != root->childs.end())
        {
            insertHelper(root->childs[charToBeAdded], word.substr(1));
        }
        else
        {
            TrieNode *newNode = new TrieNode(charToBeAdded);
            root->childs[charToBeAdded] = newNode;
            insertHelper(root->childs[charToBeAdded], word.substr(1));
        }
    }
    void insert(string word) { insertHelper(this->root, word); }
    bool searchHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        char charToBeSearched = word[0];
        if (root->childs.find(charToBeSearched) != root->childs.end())
        {
            return searchHelper(root->childs[charToBeSearched], word.substr(1));
        }
        return false;
    }
    bool search(string word) { return searchHelper(this->root, word); }
    bool startsWithHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }
        char charToBeSearched = word[0];
        if (root->childs.find(charToBeSearched) != root->childs.end())
        {
            return startsWithHelper(root->childs[charToBeSearched],
                                    word.substr(1));
        }
        return false;
    }
    bool startsWith(string prefix)
    {
        return startsWithHelper(this->root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */