#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
int main()
{
    system("cls");
    // Creating Max Heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(1);
    pq.push(14);
    pq.push(4);
    pq.push(60);
    cout << pq.top() << endl;
    cout << pq.size() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << pq.size() << endl;

    // Creating Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    pq.push(10);
    pq.push(1);
    pq.push(14);
    pq.push(4);
    pq.push(60);
    cout << pq.top() << endl;
    cout << pq.size() << endl;
    pq.pop();
    cout << pq.top() << endl;
    cout << pq.size() << endl;
    return 0;
}