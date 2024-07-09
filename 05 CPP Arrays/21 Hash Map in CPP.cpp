#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> myMap = {  //inserting element directly in map 
  {"One", 1}, 
  {"Two", 2}, 
  {"Three", 3} 
}; 

   myMap.insert(make_pair("Abhi",27));
    // Printing Values using for loop
    // Create interator first
    unordered_map<string, int> :: iterator it;

    cout<<"Printing Using For Loop"<<endl;

    for( it = myMap.begin() ; it != myMap.end() ; it++){
        string key = it->first;
        int val = it->second;
        cout<<"Key -> "<<key<<" Val -> "<<val<<endl;
    }

    myMap.erase("Abhi");
    cout<<"Printing Using For Each Loop"<<endl;
    for( auto it : myMap){
        string key = it.first;
        int val = it.second;
        cout<<"Key -> "<<key<<" Val -> "<<val<<endl;
    }

    if(myMap.find("Abhi") != myMap.end()){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    if(myMap.find("Abhijit") != myMap.end()){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}