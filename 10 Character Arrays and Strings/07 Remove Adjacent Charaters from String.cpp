#include<iostream>
using namespace std;

string removeDuplicateAdjacentCharacters( string str){
    string ans = "";
    for( int i = 0 ; i < str.length() ; i++){
            if( ans.empty() ){
                ans.push_back(str[i]);
            }else{
                if( ans.back() == str[i]){
                    ans.pop_back();
                }else{
                    ans.push_back(str[i]);
                }
            }
    }
    return ans;
}

int main()
{
    string str ="abbaca";
    string ans = removeDuplicateAdjacentCharacters(str);
    cout<<"Ans string is "<<ans<<endl;
    return 0;

}