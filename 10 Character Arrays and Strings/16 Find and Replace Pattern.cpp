#include<iostream>
#include<vector>
#include <map>
#include<string.h>
#include <string> 
#include <cmath>
using namespace std;
int convertPat(string pattern){
    map<char,int> mp;
    int idx = 1;
    for( int i = 0 ; i< pattern.length() ; i++){

        if(!(mp.find(pattern[i]) != mp.end()) ){
                mp[pattern[i]] = idx;
                
        }else{
            mp[pattern[i]] =  mp[pattern[i]]+1;
        }
    }
    int ans=0;
      for( int i = 0 ; i< pattern.length() ; i++){
        ans = ans + mp[pattern[i]]*pow(10, i);
      }
    return ans;
}
void convertWords( vector<string> a, vector<int> &b){
    for(int i = 0 ; i < a.size() ; i++){
            b.push_back( convertPat( a[i]) );
    }
}
void printArray ( vector<string> a){
   
    
     for( int i = 0 ; i < a.size()  ; i++){
        cout<<a[i]<<" " ;
    }
}
int main()
{
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    vector<int> pats;
    vector<string> ansr;
    string pattern = "abb";
    int ans = convertPat(pattern);
    convertWords(words,pats);
    for( int i = 0 ; i < pats.size() ; i++){
        if( ans == pats[i]){
            ansr.push_back(words[i]);
        }
    }
    printArray(ansr);
    
    return 0;
}