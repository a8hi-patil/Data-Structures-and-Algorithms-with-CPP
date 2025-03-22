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

void insert(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    if (root->childs.find(ch) != root->childs.end())
    {
        insert(root->childs[ch], word.substr(1));
    }
    else
    {
        TrieNode *newNode = new TrieNode(ch);
        root->childs[ch] = newNode;
        insert(root->childs[ch], word.substr(1));
    }
}

void longestCommonPrefixHelper(TrieNode *root, string &ans)
{
    if (root->isTerminal)
        return;
    if (root->childs.size() != 1)
    {
        return;
    }
    auto it = root->childs.begin();
    ans += it->first;
    longestCommonPrefixHelper(root->childs[it->first], ans);
}

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        TrieNode *root = new TrieNode('-');
        for (auto a : strs)
        {
            insert(root, a);
        }
        string ans = "";
        longestCommonPrefixHelper(root, ans);
        return ans;
    }
};