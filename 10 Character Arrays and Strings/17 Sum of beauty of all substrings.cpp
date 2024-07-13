#include<iostream>
#include <cstdlib>
#include<unordered_map>
#include<string>
using namespace std;
int calculateBeauty( unordered_map<char,int> &mp){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for( auto each:mp){
        maxi = max( maxi, each.second);
        mini = min( mini, each.second);
    }
    return maxi - mini;
}
int findBeauty( string s){
    if(s.length() == 0){
        return 0;
    }
    unordered_map<char,int> mp;
    for( int i = 0 ; i < s.length() ; i++){
        mp[s[i]]++;
    }    
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for( auto each:mp){
        maxi = max( maxi, each.second);
        mini = min( mini, each.second);
    }
    cout<<s<<" "<<maxi - mini<<endl;
    return maxi - mini;
}
int beautySum(string s){
    unordered_map<char,int> mp;
    int beautySum = 0;
    for (int i = 0; i < s.length(); i++)
    {   
        mp.clear();
        for (int j = i; j < s.length() ; j++)
        {
            mp[s[j]]++;
            beautySum+=calculateBeauty(mp);
        }
        
    }
    
return beautySum;
}
int main()
{
    system("cls");
    string s = "aabcb";
    int ans = beautySum(s);
    cout<<"Sum of beauty of "<<s<<" string is "<<ans<<endl;
    return 0;
}