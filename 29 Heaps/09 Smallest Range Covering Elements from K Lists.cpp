class Info
{
public:
    int data;
    int rowIdx;
    int colIdx;
    int size;
};

class compare
{
public:
    bool operator()(Info *a, Info *b) { return a->data > b->data; }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int totalRows = nums.size();
        for (int i = 0; i < totalRows; i++)
        {
            Info *temp = new Info(nums[i][0], i, 0, nums[i].size());
            pq.push(temp);
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
        }
        int ans_mini = mini;
        int ans_maxi = maxi;
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            mini = front->data;
            if ((ans_maxi - ans_mini) > (maxi - mini))
            {
                ans_maxi = maxi;
                ans_mini = mini;
            }
            if (front->colIdx + 1 < front->size)
            {
                Info *temp =
                    new Info(nums[front->rowIdx][front->colIdx + 1],
                             front->rowIdx, front->colIdx + 1, front->size);
                pq.push(temp);
                maxi = max(maxi, nums[front->rowIdx][front->colIdx + 1]);
            }
            else
            {
                break;
            }
        }
        vector<int> ans;
        ans.push_back(ans_mini);
        ans.push_back(ans_maxi);
        return ans;
    }
};