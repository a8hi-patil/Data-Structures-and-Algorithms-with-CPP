#include<iostream>
#include<string>
#include<string.h>
using namespace std;
bool removeKcharFromStringIfSame( string &ans, int k){
    if( ans.length() < k) return false;
    int flag = true;
    for( int i = ans.length() -k ; i <= ans.length() ; i++){
        if( ans[i]!=ans[ans.length()-1] ){
            flag = false;
            break;
        }
        if( flag ){
            ans.erase(ans.length() -k,ans.length() );
        }

    }
    return flag;
       
}
string removeDuplicates( string str, int k){
    string ans = "";
    for( int i = 0 ; i<str.length() ;i++){

        
    if( ans.length() >= k){
            bool flag =  removeKcharFromStringIfSame(ans,k);
            if( flag){
                while (flag) {
                    flag =  removeKcharFromStringIfSame(ans,k);
                }
                 if( ans.empty()){
                ans.push_back(str[i]);
                }
            }else{
                ans.push_back(str[i]);
                bool flag =  removeKcharFromStringIfSame(ans,k);
            if( flag){
                while (flag) {
                    flag =  removeKcharFromStringIfSame(ans,k);
                }
                if( ans.empty()){
                ans.push_back(str[i]);
                }
            }
            }
    }else{
        ans.push_back(str[i]);
         
    }
    
    }
    return ans;
}

string removeDuplicatesT(string str, int k){
    string masterStack="";
    string tempStack="";
    for( int i = 0 ; i<str.length() ;i++){
        
        if( masterStack.empty()){
        tempStack.push_back(str[i]);
        masterStack.push_back(tempStack.back());
        tempStack.pop_back();
        }else if(!masterStack.empty()&& !tempStack.empty() && masterStack.back() != tempStack.back() ) {
            //master stack is not empty
            tempStack.pop_back();
        }else if( !masterStack.empty()&& !tempStack.empty() && masterStack.back() == tempStack.back() && str[i]==tempStack.back() ){
            tempStack.push_back( str[i]);
        }
       

        cout<<"ms->"<<masterStack<<endl;
        cout<<"ts->"<<tempStack<<endl;

    }
    return masterStack;
}

int main()
{
    string str ="deeedbbcccbdaa";
    // string str ="eekkkddd";
    int k = 3;
    // bool flag = removeKcharFromStringIfSame(str,k);
    // while (flag)
    // {
    //     flag = removeKcharFromStringIfSame(str,k);
    //     cout<<"A";
    // }
    
     string ans = removeDuplicatesT(str,k);
    cout<<"Ans string is "<<ans<<endl;
    return 0;

}