#include <iostream>
#include <cstdlib>
using namespace std;
class Heap
{
public:
    int *arr;
    int index;
    int capacity;
    Heap(int n)
    {
        this->arr = new int[n];
        this->capacity = n;
        this->index = 0;
    }
    void printHeap()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void insert(int ele)
    {
        if (index == capacity)
        {
            cout << "Heap Overflow " << endl;
            return;
        }
        index++;
        arr[index] = ele;

        int newIdx = index;
        while (newIdx > 1)
        {
            int parentIdx = newIdx / 2;
            if (arr[parentIdx] < arr[newIdx])
            {
                swap(arr[parentIdx], arr[newIdx]);
                newIdx = parentIdx;
            }
            else
            {
                break;
            }
        }
    }
    void heapify(int arr[], int n, int idx)
    {
        int leftIdx = 2 * idx;
        int rightIdx = 2 * idx + 1;
        int largestIdx = idx;

        if (leftIdx < n && arr[leftIdx] > arr[largestIdx])
        {
            largestIdx = leftIdx;
        }
        if (rightIdx < n && arr[rightIdx] > arr[largestIdx])
        {
            largestIdx = rightIdx;
        }
        if (largestIdx != idx)
        {
            swap(arr[idx], arr[largestIdx]);
            heapify(arr, n, largestIdx);
        }
    }
    void dlt()
    {
        if (index == 0)
        {
            cout << "Head  Underflow" << endl;
            return;
        }
        swap(arr[index], arr[1]);
        index--;
        heapify(arr, index, 1);
    }
};
void heapify2(int arr[], int n, int idx)
{
    int leftIdx = 2 * idx;
    int rightIdx = 2 * idx + 1;
    int largestIdx = idx;

    if (leftIdx < n && arr[leftIdx] > arr[largestIdx])
    {
        largestIdx = leftIdx;
    }
    if (rightIdx < n && arr[rightIdx] > arr[largestIdx])
    {
        largestIdx = rightIdx;
    }
    if (largestIdx != idx)
    {
        swap(arr[idx], arr[largestIdx]);
        heapify2(arr, n, largestIdx);
    }
}
void buildHeap(int *arr, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify2(arr, n, i);
    }
}
void heapSort(int *arr, int n)
{
    int e = n - 1;
    while (e > 1)
    {
        swap(arr[e], arr[1]);
        e--;
        heapify2(arr, e + 1, 1);
    }
}
int main()
{
    system("cls");
    Heap hp(10);
    hp.insert(3);
    hp.insert(2);
    hp.insert(15);
    hp.insert(5);
    hp.insert(4);
    hp.insert(45);
    hp.dlt();
    hp.printHeap();
    int arr[] = {
        0,
        1,
        5,
        6,
        4,
        2,
        3,
    };
    int n = 7;
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