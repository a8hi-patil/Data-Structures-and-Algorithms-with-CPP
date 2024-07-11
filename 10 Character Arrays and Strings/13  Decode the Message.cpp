#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;
string decodeTheMessage( string codedMessage){
    unordered_map<char,char> secret;
    string s = "the quick brown fox jumps over the lazy dog";
    string code = "abcdefghijklmnopqrstuvwxyz";
    int pointer = 0;
    char space =' ';
    secret[space] = space;

    for( int i = 0 ; i <s.length() ; i++){
        if( !(secret.find(s[i]) != secret.end()) ){
            secret[s[i]] = code[pointer];
            pointer++;
        }
    }

    string ans="";
    for( int i = 0 ; i <codedMessage.length() ; i++){
            ans.push_back(secret[codedMessage[i]]);
    }
    return ans;

}
int main()
{
    string message = "vkbs bs t suepuv";
    string decodedMessage = decodeTheMessage(message);
    cout<<"Decoded message from code :: "<<message<<" is :: "<<decodedMessage<<endl;
    return 0;
}