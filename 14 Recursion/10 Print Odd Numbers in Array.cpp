#include<iostream>
#include <cstdlib>
using namespace std;

void printOddNumbers( int arr[],int size, int idx){
    if( size == idx){
        return;
    }
    if( arr[idx] & 1){
        cout<<arr[idx]<<" , ";
    }
    printOddNumbers( arr, size, idx+1);
}
void printEvenNumbers( int arr[],int size, int idx){
    if( size == idx){
        return;
    }
    if( !(arr[idx] % 2)){
        cout<<arr[idx]<<" , ";
    }
    printEvenNumbers( arr, size, idx+1);
}
int main()
{
    system("cls");
    int a[5] = {1,2,34,7,-5};
    int size = 5;
    printOddNumbers( a,size,0);
    cout<<endl;
    printEvenNumbers( a,size,0);
    return 0;
}