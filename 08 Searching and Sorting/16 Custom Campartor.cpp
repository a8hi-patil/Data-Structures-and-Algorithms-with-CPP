#include<iostream>
#include<vector>
using namespace std;

bool myComparator( int a , int b){
    return a<b;
}
bool myComparator2( vector<int> a, vector<int> b){
    return a[0]<b[0];
}

int main()
{
    int arr[5]={1,2,3,4,5};
    int size = 5;
    int target = 4;
    return 0;
}