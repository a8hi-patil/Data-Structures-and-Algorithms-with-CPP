#include<iostream>
#include <cstdlib>
using namespace std;
int coinChange( int a[],int size, int idx, int target ,int ans){
   if( idx == size){
    return 0;
   }

}
int main()
{
    system("cls");
    int nums[3] = {1,2,5};
    int size = 3;
    int idx = 0;
    int target = 11;
    int ans = 0;
    cout<<  coinChange( nums,size, idx);
    return 0;
}