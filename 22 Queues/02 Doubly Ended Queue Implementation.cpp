#include <iostream>
#include <cstdlib>
using namespace std;

class Dqueue
{
private:
    int *arr;
    int front;
    int end;
    int size;

public:
    Dqueue(int size)
    {
        this->arr = new int[size];
        front = -1;
        end = -1;
        this->size = size;
    }
    bool isEmpty()
    {
        if (front == -1 && end == -1)
            return true;
        return false;
    }

    void push_front(int val)
    {
        if (this->isEmpty())
        {
            front++;
            end++;
            arr[end] = val;
        }
        else if (front == 0)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }

    void push_back(int val)
    {
        if (this->isEmpty())
        {
            front++;
            end++;
            arr[end] = val;
        }
        else if (end == size - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            end++;
            arr[end] = val;
        }
    }
    void pop_front()
    {
        if (!this->isEmpty())
        {
            front++;
        }
    }
    void pop_back()
    {
        if (!this->isEmpty())
        {
            end--;
        }
    }

    void print()
    {
        for (int i = this->front; i <= this->end; i++)
        {
            cout << arr[i] << " ,";
        }
        cout << endl;
    }
};
int main()
{
    system("cls");
    Dqueue q(5);
    q.push_front(1);
    q.push_front(2);
    q.push_back(3);
    q.push_back(4);
    q.print();
    q.pop_front();
    q.print();
    q.pop_back();
    q.print();

    return 0;
}