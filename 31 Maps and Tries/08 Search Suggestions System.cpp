

class Solution
{
public:
    class TrieNode
    {
    public:
        char data;
        map<char, TrieNode *> childs;
        bool isTerminal;
        TrieNode(char ch)
        {
            this->data = ch;
            this->isTerminal = false;
        }
    };
    void insertWord(TrieNode *root, string &word, int &idx)
    {
        if (idx == word.size())
        {
            root->isTerminal = true;
            return;
        }
        char ch = word[idx];
        idx++;
        if (root->childs.find(ch) != root->childs.end())
        {
            insertWord(root->childs[ch], word, idx);
        }
        else
        {
            TrieNode *newNode = new TrieNode(ch);
            root->childs[ch] = newNode;
            insertWord(root->childs[ch], word, idx);
        }
    }
    void storeAns(TrieNode *root, string &word, vector<string> &temp)
    {
        if (root->isTerminal)
        {
            if (temp.size() == 3)
                return;
            temp.push_back(word);
        }

        for (auto el : root->childs)
        {
            word.push_back(el.first);
            storeAns(el.second, word, temp);
            word.pop_back();
        }
    }
    void findPrefix(TrieNode *root, string &word, int &idx,
                    vector<string> &temp)
    {
        if (idx == word.size())
        {
            storeAns(root, word, temp);
            return;
        }
        char ch = word[idx];
        idx++;
        if (root->childs.find(ch) != root->childs.end())
        {
            findPrefix(root->childs[ch], word, idx, temp);
        }
        return;
    }
    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord)
    {
        TrieNode *root = new TrieNode('-');
        for (string el : products)
        {
            int idx = 0;
            insertWord(root, el, idx);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.size(); i++)
        {
            vector<string> temp;
            string preFix = searchWord.substr(0, i + 1);
            int j = 0;
            findPrefix(root, preFix, j, temp);
            ans.push_back(temp);
        }
        return ans;
    }
};