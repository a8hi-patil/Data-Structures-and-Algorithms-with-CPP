#include <iostream>
#include <cstdlib>
using namespace std;
class Stack
{
public:
    int *arr;
    int capacity;
    int sizeOne;
    int sizeTwo;
    int top1;
    int top2;

    Stack(int capacity)
    {
        this->arr = new int[capacity];
        this->sizeOne = 0;
        this->sizeTwo = 0;
        this->top1 = -1;
        this->top2 = capacity;
        this->capacity = capacity;
    }
    void push1(int val)
    {
        if (this->top2 - this->top1 > 1)
        {
            this->arr[++this->top1] = val;
            this->sizeOne++;
            return;
        }
        else
        {
            cout << "Stack Over Flow";
            return;
        }
    }
    void push2(int val)
    {
        if (this->top2 - this->top1 > 1)
        {
            arr[--this->top2] = val;
            this->sizeTwo++;
            return;
        }
        else
        {
            cout << "Stack Over Flow";
            return;
        }
    }
    void pop1()
    {
        if (this->top1 == -1)
        {
            cout << "Stack is already empty " << endl;
            return;
        }
        else
        {
            arr[this->top1--] = -1;
            this->sizeOne--;
            return;
        }
    }
    void pop2()
    {
        if (this->top2 == capacity)
        {
            cout << "Stack is already empty " << endl;
            return;
        }
        else
        {
            arr[this->top2++] = -1;
            this->sizeTwo--;
            return;
        }
    }
    int getTop1()
    {
        if (this->top1 == -1)
        {
            cout << "Stack is already empty " << endl;
            return -1;
        }
        return arr[this->top1];
    }
    int getTop2()
    {
        if (this->top2 == capacity)
        {
            cout << "Stack is already empty " << endl;
            return -1;
        }
        return arr[this->top2];
    }
    bool isEmpty1()
    {
        if (this->top1 == -1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty2()
    {

        if (this->top2 == this->capacity)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            cout << this->arr[i] << " - ";
        }
    }
};
int main()
{
    system("cls");
    Stack s(5);
    cout << s.isEmpty1() << " " << s.isEmpty2() << endl;
    s.push1(1);
    s.push2(5);
    s.push1(2);
    s.push2(4);
    cout << s.getTop1() << endl;
    cout << s.getTop2() << endl;
    s.push1(6);
    s.pop1();
    s.pop2();
    s.print();
    // s.push1(6);

    return 0;
}