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
    bool searchHelper(TrieNode *root, string word, string &newWord)
    {
        if (root->isTerminal)
        {
            return true;
        }
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        char chToSearch = word[0];
        newWord.push_back(chToSearch);

        if (root->childs.find(chToSearch) != root->childs.end())
        {

            return searchHelper(root->childs[chToSearch], word.substr(1), newWord);
        }
        newWord = "";

        return false;
    }
    bool search(string word, string &newWord)
    {
        return searchHelper(this->root, word, newWord);
    }
};
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        WordDictionary wd;
        for (string el : dictionary)
        {
            wd.addWord(el);
        }
        int start = 0;
        int end = 0;
        string ans = "";
        while (end < sentence.length())
        {
            if (sentence[end] == ' ' || end == sentence.length() - 1)
            {
                int len = end == sentence.length() - 1 ? sentence.length()
                                                       : end - start;
                string temp = sentence.substr(start, len);
                string test = "";
                wd.search(temp, test);
                // cout<<test<<endl;
                // cout << temp << "->" << test << endl;
                if (test.length() == 0)
                {
                    ans += temp;
                }
                else
                {
                    ans += test;
                }
                if (sentence[end] == ' ')
                {
                    ans += " ";
                }
                start = end + 1;
            }
            end++;
        }
        return ans;
    }
};