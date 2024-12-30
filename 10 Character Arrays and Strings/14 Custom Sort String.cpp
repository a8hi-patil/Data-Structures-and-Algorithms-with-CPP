#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
string orderCopy;

bool cmp(char a, char b)
{
    return orderCopy.find(a) < orderCopy.find(b);
}

void customSort(string &s)
{
    sort(s.begin(), s.end(), cmp);
}

int main()
{
    system("cls");
    string order = "cba", s = "abcd";
    orderCopy = order;
    customSort(s);
    cout << s;
    return 0;
}