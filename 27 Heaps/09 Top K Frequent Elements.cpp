class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto num : nums)
            mp[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto entry : mp)
        {
            pq.push({entry.second, entry.first});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};