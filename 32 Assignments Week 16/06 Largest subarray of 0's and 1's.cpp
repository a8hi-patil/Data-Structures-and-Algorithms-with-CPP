class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        unordered_map<int, int> map;
        int cSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int val = arr[i] == 1 ? 1 : -1;
            cSum += val;

            if (cSum == 0)
            {
                maxLen = max(maxLen, i + 1);
            }
            else

                if (map.find(cSum) != map.end())
            {
                maxLen = max(maxLen, i - map[cSum]);
            }
            else
            {
                map[cSum] = i;
            }
        }
        return maxLen;
    }
};