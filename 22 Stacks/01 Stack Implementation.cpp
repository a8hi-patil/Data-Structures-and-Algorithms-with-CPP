#include <iostream>
#include <cstdlib>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;
    int capacity;
    Stack(int capacity)
    {
        this->arr = new int[capacity];
        this->size = 0;
        this->top = -1;
        this->capacity = capacity;
    }
    void push(int val)
    {
        if (this->top >= capacity - 1)
        {
            cout << "Stack is full cannot insert" << endl;
            return;
        }
        else
        {
            this->arr[++this->top] = val;
            this->size++;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is already empty!! Cannot perform pop operation " << endl;
            return;
        }
        else
        {
            arr[top--] = -1;
            this->size--;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    int getSize()
    {
        return this->size;
    }
    void print()
    {
        for (int i = 0; i <= this->top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    system("cls");
    Stack *s = new Stack(5);
    cout << s->isEmpty() << endl;
    cout << s->getSize() << endl;
    s->pop();
    s->push(1);
    s->push(2);
    cout << s->isEmpty() << endl;
    s->push(3);
    cout << s->getTop() << endl;
    s->push(4);
    cout << s->getSize() << endl;
    s->push(5);
    s->print();
    s->push(2);
    s->pop();
    s->print();
    return 0;
}