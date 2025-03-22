class Solution
{
    class cmp
    {
    public:
        bool operator()(vector<int> &a, vector<int> &b)
        {
            long long dia1 = pow(a[0], 2) + pow(a[1], 2);
            long long dia2 = pow(b[0], 2) + pow(b[1], 2);
            return dia1 < dia2;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        priority_queue<vector<int>, vector<vector<int>>, cmp> maxHeap;
        for (auto el : points)
        {

            maxHeap.push(el);
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return ans;
    }
};