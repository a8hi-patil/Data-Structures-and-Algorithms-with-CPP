#include <iostream>
#include <cstdlib>
using namespace std;
Node *solve(Node *head, unordered_map<Node *, Node *> &mp)
{
    if (!head)
        return head;

    Node *newNode = new Node(head->val);
    mp[head] = newNode;
    newNode->next = solve(head->next, mp);

    if (head->random)
    {
        newNode->random = mp[head->random];
    }
    return newNode;
}
Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;

    return solve(head, mp);
}
int main()
{
    system("cls");
    return 0;
}