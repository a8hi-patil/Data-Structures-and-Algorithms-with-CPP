#include<iostream>
#include <cstdlib>
#include<stack>
using namespace std;
class MinStack {
public:
     stack<long long int> s;
    int min = INT_MAX;
    stack<long long int> minStack;
    MinStack() {
        
    }
    
    void push(long long int val) {
        if( val <= this->min){
            this->min = val;
            minStack.push(this->min);
        }else{
              minStack.push(this->min);
        }
        this->s.push(val);
    }
    
    void pop() {
        this->minStack.pop();
        
        if( minStack.empty()){
            this->min = INT_MAX;
        }else{
            this->min = minStack.top();
        }
        this->s.pop();
    }
    
    int top() {
        return this->s.top();
    }
    
    int getMin() {
        return this->minStack.top();
    }
};



int main()
{
    system("cls");
    MinStack* obj = new MinStack();
        obj->push(2147483646);
        obj->push(2147483646);
        obj->push(2147483647);
        obj->pop();
        cout<<obj->getMin()<<endl;
        obj->pop();
        cout<<obj->getMin()<<endl;
        obj->pop();
        obj->push(2147483647);
        cout<<obj->getMin()<<endl;
        obj->push(-2147483648);
        cout<<obj->top()<<endl;
         cout<<obj->getMin()<<endl;
         obj->pop();
        cout<<obj->getMin()<<endl;
    return 0;
}