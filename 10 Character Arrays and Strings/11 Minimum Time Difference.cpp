#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int stringToIntTime( string s){
    return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
}
void convertStringTimeToTimeArray( vector<string> &s , vector<int> &t){

    for( int i =0 ; i< s.size() ; i++){
        t.push_back(stringToIntTime(s[i]));
    }
}
int findMinimumTimeDiffrence( vector<int> &t){
    int minTime = INT_MAX;
    sort(t.begin(),t.end());
     for( int i =0 ; i< t.size() ; i++){
        if(i+1 < t.size())
        minTime = min(minTime,t[i+1]-t[i]);
    }
    //last case
    minTime= min( minTime, 1440 + t[0]-t[t.size()-1]);
    return minTime;
}
int main()
{
    vector<string> timePoints = {"00:00","23:59","00:00"};
    vector<int> timeInMinutes;
    convertStringTimeToTimeArray(timePoints,timeInMinutes);
    cout<<findMinimumTimeDiffrence(timeInMinutes);
    return 0;
}