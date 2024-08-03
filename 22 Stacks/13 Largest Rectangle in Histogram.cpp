// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void findNextSmallIdx( vector<int> &v, vector<int> &ans){
    stack <int> s;
    s.push(-1);
    
    for( int i = v.size() -1 ; i>= 0 ; i--){
        int ele = v[i];
        while( !s.empty()&& s.top()!=-1 && ele <= v[s.top()]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i);
    }
}
void findPrevSmallIdx( vector<int> &v, vector<int> &ans){
    stack <int> s;
    s.push(-1);
    
    for( int i = 0 ; i < v.size() ; i++){
        int ele = v[i];
        while( !s.empty()&& s.top()!=-1 && ele <= v[s.top()]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i);
    }
}
int main()
{
   vector<int> v = {4,2,0,3,2,4,3,4};
    vector<int> nextSmall ;
    vector<int> prevSmall ;
    vector<int> ans ;
    findNextSmallIdx(v,nextSmall);
    reverse(nextSmall.begin(), nextSmall.end());
    findPrevSmallIdx(v,prevSmall);
    for( int i = 0 ; i < nextSmall.size() ; i++){
        if( nextSmall[i]==-1){
            nextSmall[i] = nextSmall.size();
        }
    }
    int maxArea = 0;
    for( int i = 0 ; i < nextSmall.size() ; i++){
        int width = nextSmall[i] - prevSmall[i] -1;
        int area = width * v[i];
        if( area > maxArea){
            maxArea = area;
        }
    }
    cout << "Max Area " << maxArea << endl;
    return 0;
}