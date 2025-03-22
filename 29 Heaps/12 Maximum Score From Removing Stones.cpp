class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        int cnt = 0;
        while (pq.size() > 1)
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if (top1 > 0 && top2 > 0)
            {
                top1--;
                top2--;
                cnt++;
            }
            if (top1 > 0)
            {
                pq.push(top1);
            }
            if (top2 > 0)
            {
                pq.push(top2);
            }
        }
        return cnt;
    }
};