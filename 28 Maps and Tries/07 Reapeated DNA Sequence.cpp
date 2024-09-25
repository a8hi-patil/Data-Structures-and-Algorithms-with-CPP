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

void lcp(TrieNode *root, string &ans)
{

    if (root->isTerminal)
    {
        return;
    }
    TrieNode *child;
    if (root->children.size() == 1)
    {
        for (auto i : root->children)
        {
            char ch = i.first;
            ans.push_back(ch);
            child = i.second;
        }
    }
    else
    {
        return;
    }
    lcp(child, ans);
}

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        TrieNode *root = new TrieNode('-');

        for (auto word : strs)
        {
            insertWord(root, word);
        }

        lcp(root, ans);
        return ans;
    }
};