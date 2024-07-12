#include<iostream>
#include <cstdlib>
using namespace std;

int search(int a[],int size,int idx, int target){
    if( a[idx] == target){
        return idx;
    }
    if( size == idx){
        return -1;
    }
    return search(a,size,idx + 1, target);
}

int main()
{
    system("cls");
    int a[5] = {1,2,3,4,5};
    int size = 5;
    int target = 4;
    cout<<"Target "<<target<<" found at index "<<search( a,size,0,target)<<endl;
    return 0;
}