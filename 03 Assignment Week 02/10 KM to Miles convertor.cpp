#include<iostream>
using namespace std;

float KmToMile( float km){
    return km*0.621371;
}
int main ( ){
    cout<< "Enter the KM to convert it into Miles : ";
    float km;
    cin >> km;
    float res = KmToMile( km );
    cout<<km<<" KM is "<<res<< " Miles.";
    return 0 ;
}