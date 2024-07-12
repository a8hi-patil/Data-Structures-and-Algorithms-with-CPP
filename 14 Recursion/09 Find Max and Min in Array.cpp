#include<iostream>
#include <cstdlib>
using namespace std;

int getMax(int a[],int size,int idx, int maxEle){
    if( size == idx){
        return maxEle;
    }

    return getMax( a,size,idx+1,max( a[idx],maxEle));
}

int getMin(int a[],int size,int idx, int minEle){
   
    if( size == idx){
        return minEle;
    }

    return getMin( a,size,idx+1,min( a[idx],minEle));
}

int main()
{
    system("cls");
    int a[5] = {1,2,34,4,-5};
    int size = 5;
    cout<<"Max value in array is "<<getMax( a,size,0,INT_MIN)<<endl;
    cout<<"Min value in array is "<<getMin( a,size,0,INT_MAX)<<endl;
    return 0;
}