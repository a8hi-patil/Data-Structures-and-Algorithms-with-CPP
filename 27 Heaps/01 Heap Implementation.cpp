#include <iostream>
using namespace std;

class Heap
{
private:
    int *arr;
    int capacity;
    int index;

public:
    Heap(int n)
    {
        this->arr = new int[n];
        this->capacity = n;
        this->index = 0;
    }
    void printHeap()
    {
        for (int i = 1; i < this->capacity; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int ele)
    {
        if (index == capacity - 1)
        {
            cout << "Heap is overflow " << endl;
            return;
        }
        index++;
        arr[index] = ele;
        int i = index;
        while (i > 1)
        {
            int parentIndex = i / 2;

            if (arr[parentIndex] < arr[i])
            {
                swap(arr[parentIndex], arr[i]);
                i = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapify(int *arr, int n, int currIdx)
    {
        int i = currIdx;
        int leftIdx = 2 * i;
        int rightIdx = 2 * i + 1;

        int largestIdx = i;
        if (leftIdx < n && arr[leftIdx] > arr[largestIdx])
        {
            largestIdx = leftIdx;
        }
        if (rightIdx < n && arr[rightIdx] > arr[largestIdx])
        {
            largestIdx = rightIdx;
        }

        if (largestIdx != i)
        {
            swap(arr[largestIdx], arr[i]);
            i = largestIdx;
            heapify(arr, n, i);
        }
    }
};
void heapify(int *arr, int n, int currIdx)
{
    int i = currIdx;
    int leftIdx = 2 * i;
    int rightIdx = 2 * i + 1;

    int largestIdx = i;
    if (leftIdx < n && arr[leftIdx] > arr[largestIdx])
    {
        largestIdx = leftIdx;
    }
    if (rightIdx < n && arr[rightIdx] > arr[largestIdx])
    {
        largestIdx = rightIdx;
    }

    if (largestIdx != i)
    {
        swap(arr[largestIdx], arr[i]);
        i = largestIdx;
        heapify(arr, n, i);
    }
}

void buildHeap(int *arr, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}
void heapSort(int *arr, int n)
{
    int e = n - 1;
    while (e > 1)
    {
        swap(arr[e], arr[1]);
        e--;
        heapify(arr, e + 1, 1);
    }
}
int main()
{
    Heap pq(10);
    pq.insert(10);
    pq.insert(30);
    pq.insert(40);
    pq.printHeap();

    int arr[] = {
        1,
        2,
        3,
        4,
        5,
        6,
    };
    int n = 6;
    buildHeap(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}