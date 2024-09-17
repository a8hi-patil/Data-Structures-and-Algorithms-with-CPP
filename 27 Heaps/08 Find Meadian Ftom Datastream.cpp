class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = 0;
    MedianFinder() { this->median = 0; }

    void addNum(int num)
    {
        if (maxHeap.size() == minHeap.size())
        {
            if (num > median)
            {
                minHeap.push(num);
                median = minHeap.top();
            }
            else
            {
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if (maxHeap.size() + 1 == minHeap.size())
        {
            if (num > median)
            {
                int ele = minHeap.top();
                minHeap.pop();
                maxHeap.push(ele);
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else
            {
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
        else if (maxHeap.size() == minHeap.size() + 1)
        {
            if (num > median)
            {
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else
            {
                int ele = maxHeap.top();
                maxHeap.pop();
                minHeap.push(ele);
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
    }

    double findMedian() { return median; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */