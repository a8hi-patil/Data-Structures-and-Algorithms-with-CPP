#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    // Default Max Heap is Created
    priority_queue<int, vector<int>, greater<int>> pqMin;
    // Creation of Min Heap
    pq.push(10);
    pq.push(20);
    pq.push(40);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.size() << endl;
    cout << pq.empty() << endl;
    system("cls");
    return 0;
}