#include <iostream>
#include <cstdlib>
using namespace std;
Node *linkdelete(Node *head, int n, int m)
{

    Node *start = head;

    while (start)
    {
        int o = n;
        int p = m;
        p--;
        while (p && start)
        {
            start = start->next;
            p--;
        }
        if (!start)
            return head;
        Node *prev = start;

        while (o && start)
        {
            start = start->next;
            o--;
        }
        if (!start)
        {
            prev->next = NULL;
            return head;
        }

        prev->next = start->next;
        start = start->next;
    }
    return head;
}
int main()
{
    system("cls");
    return 0;
}