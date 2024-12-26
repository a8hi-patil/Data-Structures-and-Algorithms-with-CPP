#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;
int main()
{
    system("cls");

    list<int> mylist;
    mylist.push_back(1);
    mylist.push_front(2);
    mylist.pop_back();
    mylist.pop_front();
    mylist.clear();

    if (mylist.empty())
    {
        cout << "LIST IS EMPTY";
    }

    cout << mylist.front() << endl;
    cout << mylist.back() << endl;
    mylist.begin();
    mylist.end();

    return 0;
}