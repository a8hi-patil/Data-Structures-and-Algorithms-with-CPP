#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    deque<int> dq;

    dq.push_back(1);
    dq.push_front(2);
    dq.pop_front();
    dq.pop_back();
    dq.size();
    dq.front();
    dq.back();
    dq.clear();
    dq.empty();
    dq.begin();
    dq.end();
    dq[3];
    dq.at(3);

    return 0;
}