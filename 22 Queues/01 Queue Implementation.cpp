#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int front;
    int end;

public:
    Queue(int size)
    {
        this->arr = new int[size];
        this->size = size;
        this->front = -1;
        this->end = -1;
    }
    bool isEmpty()
    {
        if (front == -1 && end == -1)
            return true;
        return false;
    }
    void push(int val)
    {
        if (this->isEmpty())
        {
            front++;
            end++;
            arr[end] = val;
        }
        else
        {
            end++;
            arr[end] = val;
        }
    }
    void pop()
    {
        if (this->isEmpty())
        {
            cout << "Nothing to pop" << endl;
        }
        else if (front == end)
        {
            front = -1;
            end = -1;
        }
        else
        {
            front++;
        }
    }
    int frontE()
    {
        if (!this->isEmpty())
            return arr[front];
        return front;
    }
    int back()
    {
        if (!this->isEmpty())
            return arr[end];
        return -1;
    }
    int qSize()
    {
        if (!this->isEmpty())
            return end - front + 1;
        return -1;
    }
};

int main()
{
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.frontE() << endl;
    q.push(4);
    q.push(5);
    q.pop();
    cout << q.frontE() << endl;

    cout << q.back() << endl;
    cout << q.qSize() << endl;
    while (!q.isEmpty())
    {
        cout << q.frontE() << " ";
        q.pop();
    }
    cout << endl;
}