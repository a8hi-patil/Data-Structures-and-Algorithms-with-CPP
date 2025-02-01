#include <iostream>
#include <cstdlib>
using namespace std;
class Stack
{
private:
    int *arr;
    int capacity;
    int top1;
    int top2;

public:
    Stack(int size)
    {
        this->arr = new int[size];
        this->capacity = size;
        this->top1 = -1;
        this->top2 = size;
    }
    void push1(int val)
    {
        if (top1 + 1 == top2)
        {
            cout << "Stack 1 Over Flow" << endl;
            return;
        }
        top1++;
        arr[top1] = val;
    }
    void push2(int val)
    {
        if (top1 == top2 - 1)
        {
            cout << "Stack 2 Over Flow" << endl;
            return;
        }
        top2--;
        arr[top2] = val;
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack Under Flow" << endl;
            return;
        }
        arr[top1] = -1;
        top1--;
    }
    void pop2()
    {
        if (top2 == capacity)
        {
            cout << "Stack Under Flow" << endl;
            return;
        }
        arr[top2] = -1;
        top2--;
    }
    bool empty1()
    {
        if (top1 == -1)
        {
            return true;
        }
        return false;
    }
    bool empty2()
    {
        if (top2 >= capacity)
        {
            return true;
        }
        return false;
    }
    int getTop1()
    {
        if (this->empty1())
        {
            cout << "Stack 1 is empty " << endl;
            return -1;
        }
        return this->arr[top1];
    }
    int getTop2()
    {
        if (this->empty2())
        {
            cout << "Stack 2 is empty " << endl;
            return -1;
        }
        return this->arr[top2];
    }
    int getSize()
    {
        return capacity;
    }
};
int main()
{
    system("cls");
    Stack st(5);
    cout << st.empty1() << endl;
    cout << st.empty2() << endl;
    st.push1(1);
    st.push2(5);
    st.push1(2);
    st.push2(4);
    st.push1(3);
    st.push2(4);
    cout << st.getTop1() << endl;
    cout << st.getTop2() << endl;
    return 0;
}