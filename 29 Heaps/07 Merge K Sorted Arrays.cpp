class Info
{
public:
    int data;
    int rIdx;
    int cIdx;
    Info(int val, int x, int y)
    {
        data = val;
        rIdx = x;
        cIdx = y;
    }
};
class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;
        vector<int> ans;
        int totalCols = arr[0].size();
        for (int row = 0; row < arr.size(); row++)
        {
            Info *temp = new Info(arr[row][0], row, 0);
            pq.push(temp);
        }

        while (!pq.empty())
        {
            auto small = pq.top();
            pq.pop();
            ans.push_back(small->data);

            if (small->cIdx + 1 < totalCols)
            {
                Info *temp = new Info(arr[small->rIdx][small->cIdx + 1], small->rIdx, small->cIdx + 1);
                pq.push(temp);
            }
        }
        return ans;
    }
};