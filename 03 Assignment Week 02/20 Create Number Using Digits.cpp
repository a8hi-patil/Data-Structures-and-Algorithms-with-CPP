#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    cout << "Enter numbe of digits ";
    int n;
    cin >> n;
    int ans = 0;
    while (n)
    {
        int digit;
        cout << "Enter digit : ";
        cin >> digit;
        ans = ans * 10 + digit;
        n--;
    }
    cout << "Number is " << ans;

    return 0;
}