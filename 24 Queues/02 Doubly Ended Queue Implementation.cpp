#include<iostream>
#include <cstdlib>
using namespace std;

class Deque{
    public:
    int *arr;
    int n;
    int front;
    int end;
    Deque( int size ){
        this->n = size;
        this->arr = new int[n];
        this->front = -1;
        this->end = -1;
    }
    bool isEmpty(){
        if( this->front == -1 && this->end == -1)
        return true;
        return false;
    }
    void pushFront ( int val ){
        if( this->isEmpty()){
            this->front++;
            arr[this->front] = val;
            this->end++;
        }else if( this->front == 0){
            cout<<"Stack overflow";
            
        }else{
            this->front--;
            arr[this->front] = val; 
        }
    }
    void pushBack ( int val){
        if( this-> end == this->n -1){
            cout<<"Deque overflow"<<endl;
            return;
        }
        if( this->isEmpty()){
            this->front++;
            arr[this->front] = val;
            this->end++;
        }else{
            this->end++;
            arr[this->end] = val;
        }
    }
    void popFront (  ){
        if( this->isEmpty()){
           cout<<"Deque underflow"<<endl;
        }else if(this->front == this->end){
            arr[this->end] = -1;
            this->end = -1;
            this->front = -1;
        }else{
            arr[this->front] = -1;
            this->front++;
        }
    }
    void popBack ( ){
        if( this->isEmpty()){
           cout<<"Deque underflow"<<endl;
        }else if(this->front == this->end){
            arr[this->end] = -1;
            this->end = -1;
            this->front = -1;
        }else{
            arr[this->end] = -1;
            this->end--;
        }
    }

    void print( ){
        for( int i = this->front ; i <= this->end ; i++){
            cout<<arr[i]<<" ,";
        }
        cout<<endl;
    }
};

int main()
{
    system("cls");
    Deque d( 5 );
    cout<<" Is empty "<<d.isEmpty()<<endl;
    d.pushBack(5);
    d.pushBack(6);
    d.pushBack(7);
    d.popFront();
    d.pushFront(100);
    d.popBack();
    d.print();
    return 0;
}