class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {

        unordered_map<string, int> map;
        vector<string> ans;
        if (s.length() < 10)
            return ans;

        for (int i = 0; i <= s.length() - 10; i++)
        {
            map[s.substr(i, 10)]++;
        }
        for (auto el : map)
        {
            if (el.second > 1)
                ans.push_back(el.first);
        }
        return ans;
    }
};