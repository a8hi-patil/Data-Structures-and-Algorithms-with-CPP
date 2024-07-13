#include<iostream>
#include <cstdlib>
#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int sherlockAndAnagrams(string s) {
    unordered_map <string , int> mp;
    int countOfPairs = 0;
    for( int i = 0 ; i< s.length() ; i++){
        for( int j = 1 ; j <= s.length() - i  ; j++){
            string sub = s.substr(i,j);
            sort(sub.begin(),sub.end());
            mp[sub]++;
    }
    }

    for( auto e : mp){
        countOfPairs += (e.second*(e.second -1))/2;
    }

    return countOfPairs;

}
int main()
{
    system("cls");
    string s = "abba";
    int ans  = sherlockAndAnagrams(s);
    cout<<"Anagramatic substring are "<<ans<<endl;
    return 0;
}