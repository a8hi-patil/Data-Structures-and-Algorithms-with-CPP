#include<iostream>
#include<vector>
using namespace std;

bool findPalindrom( char arr[],int size){
        int start = 0;
        int end = size -1;
        int isPalindrom = true;
        while( start < end){
            if( arr[start] != arr[end]){
                return false;
            }
            start++;
            end--;
        }
        return isPalindrom;
}
int main()
{
    char name[]={'n','i','t','i','n'};
    int size = 5;
    if( findPalindrom(name,size)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}