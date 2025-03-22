class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;

        for (auto num : nums)
            map[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto el : map)
        {
            minHeap.push({el.second, el.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }
        vector<int> ans;
        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};