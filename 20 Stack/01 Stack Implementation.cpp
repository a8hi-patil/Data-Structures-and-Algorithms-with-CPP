#include <iostream>
#include <cstdlib>
using namespace std;
class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        this->arr = new int[size];
        this->top = -1;
        this->capacity = size;
    }
    void push(int val)
    {
        if (this->top >= capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = val;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        this->arr[this->top] = -1;
        this->top--;
    }
    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }
    int getTop()
    {
        if (this->empty())
        {
            cout << "Stack in empty " << endl;
            return -1;
        }
        return this->arr[this->top];
    }
    int getSize()
    {
        return this->capacity;
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
    Stack st(5);
    cout << st.getSize() << endl;
    st.pop();
    cout << st.empty() << endl;
    st.push(5);
    st.push(4);
    cout << st.getTop() << endl;
    st.push(3);
    st.push(2);
    st.push(1);
    cout << st.getTop() << endl;
    cout << st.empty() << endl;
    st.print();
    st.push(1);

    return 0;
}