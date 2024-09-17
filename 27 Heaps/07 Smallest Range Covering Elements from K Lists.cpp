class Info
{
public:
    int data;
    int row;
    int col;
    Info(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
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
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int totalRows = nums.size();
        int totalCols = nums[0].size();

        for (int i = 0; i < totalRows; i++)
        {
            Info *temp = new Info(nums[i][0], i, 0);
            pq.push(temp);
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]);
        }
        // cout<<"max,min"<<maxi<<" "<<mini<<endl;
        int ans_start = mini;
        int ans_end = maxi;
        while (!pq.empty())
        {
            Info *front = pq.top();
            pq.pop();
            int fData = front->data;
            mini = fData;
            int fRow = front->row;
            int fCol = front->col;

            if ((ans_end - ans_start) > (maxi - mini))
            {
                ans_start = mini;
                ans_end = maxi;
            }
            int currentCol = nums[fRow].size();
            if (fCol + 1 < currentCol)
            {

                Info *temp = new Info(nums[fRow][fCol + 1], fRow, fCol + 1);
                pq.push(temp);
                maxi = max(maxi, nums[fRow][fCol + 1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
    }
};