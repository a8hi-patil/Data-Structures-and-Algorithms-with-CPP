class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int> &arr)
    {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < arr.size(); i++)
        {
            heap.push(arr[i]);
        }
        int minCost = 0;
        while (heap.size() != 1)
        {
            int top1 = heap.top();
            heap.pop();
            int top2 = heap.top();
            heap.pop();
            int cost = top1 + top2;
            minCost += cost;
            heap.push(cost);
        }
        return minCost;
    }
};