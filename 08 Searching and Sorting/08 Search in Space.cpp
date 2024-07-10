#include<iostream>
using namespace std;

int searchInSpace( int divident, int divisor){
    int start = 0 ;
    int end = divident;
    int mid = start + ( end - start)/2;
    int ans = -1;
    while( start <= end){
        if( divisor * mid == divident ){
            return mid;
        }else if( divisor * mid < divident  ){
            ans = mid;
            start = mid +1;
        }else{
            end = mid -1;
        }
         mid = start + ( end - start)/2;
    }
    return ans;
}

int main()
{
        cout<< "9 / 3 = "<<searchInSpace(9,3)<<endl;
   
    return 0;
}