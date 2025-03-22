class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> hash(26, 0);
        for (char ch : tasks)
        {
            hash[ch - 'A']++;
        }
        priority_queue<int> maxHeap;

        int time = 0;

        for (int i = 0; i < 26; i++)
        {
            if (hash[i] > 0)
            {
                maxHeap.push(hash[i]);
            }
        }
        while (!maxHeap.empty())
        {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++)
            {
                if (!maxHeap.empty())
                {
                    int top = maxHeap.top();
                    maxHeap.pop();
                    top--;
                    temp.push_back(top);
                }
            }
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] > 0)
                {
                    maxHeap.push(temp[i]);
                }
            }
            if (maxHeap.empty())
            {
                time += temp.size();
            }
            else
            {
                time += n + 1;
            }
        }
        return time;
    }
};