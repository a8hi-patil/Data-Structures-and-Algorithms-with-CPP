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

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary() { this->root = new TrieNode('-'); }

    void addWordHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        char chTobeAdded = word[0];
        if (root->childs.find(chTobeAdded) != root->childs.end())
        {
            addWordHelper(root->childs[chTobeAdded], word.substr(1));
        }
        else
        {
            TrieNode *newNode = new TrieNode(chTobeAdded);
            root->childs[chTobeAdded] = newNode;
            addWordHelper(root->childs[chTobeAdded], word.substr(1));
        }
    }
    void addWord(string word) { addWordHelper(this->root, word); }
    bool searchHelper(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        char chToSearch = word[0];

        if (chToSearch == '.')
        {
            for (auto el : root->childs)
            {
                if (searchHelper(el.second, word.substr(1)))
                {
                    return true;
                }
            }
        }
        else if (root->childs.find(chToSearch) != root->childs.end())
        {
            return searchHelper(root->childs[chToSearch], word.substr(1));
        }
        return false;
    }
    bool search(string word) { return searchHelper(this->root, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */