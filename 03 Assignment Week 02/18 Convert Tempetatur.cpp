#include<iostream>
using namespace std;

void convertTempetature(float celsius){
    cout<<"The "<<celsius<<" celsius in kelvin is "<<celsius+273.15<<" and in farenheit is "<< celsius*1.8 + 32;
}
int main (){
    float celsius;
    cout<<"Enter temperature in celsius : ";
    cin>>celsius;
    convertTempetature( celsius);
    return 0;
}