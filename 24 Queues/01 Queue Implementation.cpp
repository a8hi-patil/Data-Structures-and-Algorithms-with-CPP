#include<iostream>
#include <cstdlib>
using namespace std;
class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    
    Queue( int n){
        this->arr = new int[n];
        this->size = n;
        this->front = -1;
        this->rear = -1;
    }
    bool empty(){
        if( this->front == -1 && this->rear == -1){
            return true;
        }
        return false;
    }
    void push(int val){
        if( this->rear >= this->size){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if( this->front == -1 && this->rear == -1){
            this->rear++;
            this->front++;
            this->arr[this->front] = val;
        }else{
            this->arr[++this->rear] = val;
        }
    }
    void pop(){
        if( this->front == -1 && this->rear == -1 ){
            cout<<"Empty Queue !!"<<endl;
            return;
        }else if( this->front == this->rear){
            this->arr[this->rear] = -1;
            this->front = -1;
            this->rear = -1;
        }else{
            arr[this->front++] = -1;
        }
    }
    int frontE(){
        if( this->front == -1 && this->rear == -1){
            cout<<"Ques is empty "<<endl;
            return 0;
        }
        return arr[this->front];
    }
    int rearE(){
        if( this->front == -1 && this->rear == -1){
            cout<<"Ques is empty "<<endl;
            return 0;
        }
        return arr[this->rear];
    }
    int sizeE(){
        if( this->front == -1 && this->rear == -1){

            cout<<"Ques is empty "<<endl;
            return 0;
        }
        return rear - front +1;
        }
    
    
};
int main()
{
    system("cls");
    Queue q (6);
    cout<<q.empty()<<endl;
    q.push(1);
    cout<<q.empty()<<endl;
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.sizeE()<<endl;
    cout<<q.frontE()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.frontE()<<endl;
}