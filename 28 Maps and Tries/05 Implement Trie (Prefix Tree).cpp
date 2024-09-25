class TrieNode
{
public:
    char data;
    unordered_map<char, TrieNode *> children;
    bool isTerminal;
    TrieNode(char val)
    {
        data = val;
        isTerminal = false;
    }
};
void insertWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode *child;
    if (root->children.find(ch) != root->children.end())
    {
        // child found
        child = root->children[ch];
    }
    else
    {
        // if not found
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertWord(child, word.substr(1));
}
bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    // logic
    char ch = word[0];
    TrieNode *child;
    if (root->children.find(ch) != root->children.end())
    {
        // found
        child = root->children[ch];
    }
    else
    {
        // not found
        return false;
    }

    // recursive call
    return searchWord(child, word.substr(1));
}

bool searchPrefix(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return true;
    }

    // logic
    char ch = word[0];
    TrieNode *child;
    if (root->children.find(ch) != root->children.end())
    {
        // found
        child = root->children[ch];
    }
    else
    {
        // not found
        return false;
    }

    // recursive call
    return searchPrefix(child, word.substr(1));
}
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('-');
    }

    void insert(string word)
    {
        insertWord(root, word);
    }

    bool search(string word)
    {
        return searchWord(root, word);
    }

    bool startsWith(string prefix)
    {
        return searchPrefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */