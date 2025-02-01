#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Car
{
public:
    int pos;
    int spd;
    Car(int p, int s) : pos(p), spd(s) {};
};
static bool cstmCmp(Car &a, Car &b)
{
    return a.pos < b.pos;
}
int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<Car> cars;
    for (int i = 0; i < position.size(); i++)
    {
        Car car(position[i], speed[i]);
        cars.push_back(car);
    }
    sort(cars.begin(), cars.end(), cstmCmp);

    stack<float> st;
    for (auto car : cars)
    {
        float time = (target - car.pos) / ((float)car.spd);
        while (!st.empty() && st.top() <= time)
            st.pop();
        st.push(time);
    }
    return st.size();
}
int main()
{
    system("cls");
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;
    cout << carFleet(target, position, speed);

    return 0;
}