#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    queue<int> q; // FIFO
    q.push(1);
    q.pop();
    q.size();
    q.front();
    q.back();
    q.empty();
    return 0;
}