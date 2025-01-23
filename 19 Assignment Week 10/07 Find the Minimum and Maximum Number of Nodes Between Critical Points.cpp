#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> ans = {-1, -1};
    if (!head || !head->next || !head->next->next)
    {
        return ans;
    }
    ListNode *prev = head;
    ListNode *curr = head->next;
    ListNode *nxt = head->next->next;
    int i = 2;
    int minDist = INT_MAX;
    int firstCP = -1;
    int lastCP = -1;

    while (nxt)
    {
        bool isCP = ((curr->data < prev->data && curr->data < nxt->data) || (curr->data > prev->data && curr->data > nxt->data)) ? true : false;

        if (isCP && firstCP == -1)
        {
            firstCP = i;
            lastCP = i;
        }
        else if (isCP)
        {
            minDist = min(minDist, i - lastCP);
            lastCP = i;
        }
        i++;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    if (firstCP == lastCP)
    {
        return ans;
    }
    else
    {
        ans[0] = minDist;
        ans[1] = lastCP - firstCP;
    }
    return ans;
}
int main()
{
    system("cls");
    return 0;
}