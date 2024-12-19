#include <iostream>
#include <cstdlib>
using namespace std;
float KmToMile(float km)
{
    return km * 0.621371;
}

int main()
{
    system("cls");
    cout << "Enter KM : ";
    float km;
    cin >> km;
    cout << km << " to miles is " << KmToMile(km);
    return 0;
}