#include <iostream>
#include <cstdlib>
using namespace std;

int cstoi(string s)
{
    int i = 0;
    int sign = 1;
    long long int sum = 0;
    while (i < s.length() && s[i] == ' ')
    {
        i++;
    }

    if (i < s.length() && (s[i] == '+' || s[i] == '-'))
    {
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }
    while (i < s.length() && isdigit(s[i]))
    {
        sum = sum * 10 + (s[i] - '0');
        if (sum * sign < INT_MIN)
        {
            return INT_MIN;
        }
        if (sum * sign > INT_MAX)
        {
            return INT_MAX;
        }
        i++;
    }
    sum = sum * sign;

    return sum;
}
int main()
{
    system("cls");
    string s = "-91283472332";
    cout << cstoi(s);

    return 0;
}