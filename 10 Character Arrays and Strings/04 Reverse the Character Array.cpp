#include<iostream>
#include<vector>
using namespace std;

void reverse( char arr[],int size){
        int start = 0;
        int end = size -1;
        while( start < end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
}
int main()
{
    char name[]={'a','b','h','i'};
    int size = 4;
    reverse(name,size);
    cout<<name;
    return 0;
}