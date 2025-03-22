class Solution
{
public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> map;
        for (int el : a)
            map[el]++;
        for (int el : b)
        {
            if (map.find(el) != map.end())
            {
                if (map[el] < 1)
                {
                    return false;
                }
                map[el]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};