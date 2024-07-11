#include<iostream>
using namespace std;
bool checkPalindrom( string s, int start, int end){
    bool isPalindrom = true;
    while (start <= end)
    {
      if( s[start] != s[end]){
        isPalindrom = false;
        break;
      }
      start++;
      end--;
    }
    return isPalindrom;
}
bool checkValindPalindrom( string s){
    int start = 0;
    int end = s.length() -1;
    while( start <= end){
        if( s[start] == s[end]){
            start++;
            end--;
        }else{
            bool firstHalf = checkPalindrom(s,start+1,end);
            bool secondHalf = checkPalindrom(s,start,end-1);
            return firstHalf || secondHalf;
        }
    }
        return true;
}
int main()
{
   string  s = "aba";
   cout<<checkValindPalindrom(s);
    return 0;
}