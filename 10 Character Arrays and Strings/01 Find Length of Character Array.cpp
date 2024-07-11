#include<iostream>
using namespace std;
int findLengthOfCharArray( char arr[]){
    int idx = 0;
    while(arr[idx] != '\n'){
        idx++;
    }
    return idx + 1;
}
int main()
{
    char name[4]={'a','b','h','i'};
    int size = 4;
    cout<<"Size of character array is "<<findLengthOfCharArray(name)<<endl;
    return 0;
}