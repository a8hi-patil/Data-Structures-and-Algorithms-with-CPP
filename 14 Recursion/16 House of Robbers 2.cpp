#include<iostream>
#include <cstdlib>
#include<vector>
using namespace std;
int rob( vector<int> nums,int s, int e){
    if( e < 0){
        return nums[0];
    }
    if( s > e){
        return 0;
    }
    return max( nums[s]+rob(nums,s+2,e), rob(nums,s+1,e));
}
int main()
{
    system("cls");
    vector <int>  nums = {2};
    cout<<max(rob(nums,0,nums.size()-2),rob(nums,1,nums.size()-1));
    return 0;
}   