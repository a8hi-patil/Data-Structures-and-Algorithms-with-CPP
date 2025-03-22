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

class MagicDictionary
{
public:
    TrieNode *root;
    MagicDictionary() { this->root = new TrieNode('-'); }
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
    void buildDict(vector<string> dictionary)
    {
        for (auto el : dictionary)
        {
            addWord(el);
        }
    }
    bool searchHelper(TrieNode *root, string word, bool canWeSkip)
    {
        if (word.length() == 0)
        {

            return canWeSkip && root->isTerminal;
        }
        char chToSearch = word[0];
        bool ans = false;
        if (root->childs.find(chToSearch) != root->childs.end())
        {
            if (searchHelper(root->childs[chToSearch], word.substr(1),
                             canWeSkip))
                return true;
        }
        if (!canWeSkip)
        {
            for (auto el : root->childs)
            {
                if (chToSearch != el.first &&
                    searchHelper(el.second, word.substr(1), true))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool search(string word)
    {
        bool canWeSkip = false;
        return searchHelper(this->root, word, canWeSkip);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */