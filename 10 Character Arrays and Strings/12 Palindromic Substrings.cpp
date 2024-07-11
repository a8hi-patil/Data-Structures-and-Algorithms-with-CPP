#include<iostream>
#include<string.h>
using namespace std;

int expandAroundCenter( string s , int start, int end){
    int count=0;
    while( start >=0 && end< s.length() && s[start] == s[end]){
        count++;
        start--;
        end++;
    }
    return count;
}
int calculatePalindromicSubstrings( string s){
    int totalCount = 0;
    for( int center =0 ; center < s.length() ; center++){
        int i = center;
        int j = center;
        int countOfOddSubstring = expandAroundCenter( s, i ,j);
        int countOfEvenSubstring = expandAroundCenter( s, i ,j+1);

        totalCount = totalCount + countOfOddSubstring + countOfEvenSubstring;
    }
    return totalCount;
}

int main(){
    string s = "aaa";
    int ans = calculatePalindromicSubstrings( s );
    cout<<"Palindromic sub string are "<< ans<<" !";
    return 0;
}