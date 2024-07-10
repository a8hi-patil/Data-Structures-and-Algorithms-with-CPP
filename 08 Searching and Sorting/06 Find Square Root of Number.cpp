#include<iostream>
using namespace std;

int findSquareRoot( int num){
    int start = 0;
    int end = num;
    int ans = -1;
    long long int mid = start + ( end - start)/2;
    while( start <= end){
        long long int product = mid * mid;
        if( product == num){
            return mid;
        }else if( product > num){
          
            end = mid -1;
        }else{
              ans = start;
            start = mid+1;
        }
         mid = start + ( end - start)/2;
    }
    return ans;
}

int main()
{
   cout<<"Squar Root of 4 is "<<findSquareRoot(2);
    return 0;
}