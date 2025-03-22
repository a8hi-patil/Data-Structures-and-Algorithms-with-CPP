class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double med = 0;
    MedianFinder() {}

    void addNum(int num)
    {
        if (minHeap.size() == maxHeap.size())
        {
            if (num > med)
            {
                minHeap.push(num);
                med = minHeap.top();
            }
            else
            {
                maxHeap.push(num);
                med = maxHeap.top();
            }
        }
        else if (minHeap.size() + 1 == maxHeap.size())
        {
            if (num > med)
            {
                minHeap.push(num);
                med = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            else
            {
                int el = maxHeap.top();
                maxHeap.pop();
                minHeap.push(el);
                maxHeap.push(num);
                med = (minHeap.top() + maxHeap.top()) / 2.0;
            }
        }
        else if (minHeap.size() == maxHeap.size() + 1)
        {
            if (num > med)
            {
                int el = minHeap.top();
                minHeap.pop();
                maxHeap.push(el);
                minHeap.push(num);
                med = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            else
            {
                maxHeap.push(num);
                med = (minHeap.top() + maxHeap.top()) / 2.0;
            }
        }
    }

    double findMedian() { return med; }
};
