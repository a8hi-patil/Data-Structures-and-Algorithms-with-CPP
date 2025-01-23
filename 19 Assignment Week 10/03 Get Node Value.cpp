#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *it = head;
    while (it)
    {
        cout << it->data << "->";
        it = it->next;
    }
    cout << "NULL" << endl;
    ;
}
Node *insertAtHead(int val, Node *head, Node *tail)
{
    Node *newNode = new Node(val);
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return head;
    }
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
}
int getNodeValue(Node *head, int pos)
{
    if (head == NULL)
    {
        return -1;
    }
    pos++;
    Node *it = head;
    Node *ans = head;
    while (it)
    {
        it = it->next;
        if (pos <= 0)
        {
            ans = ans->next;
        }
        pos--;
    }
    return ans->data;
}

void solve(Node *head, int &pos, int &ans)
{
    if (head == NULL)
    {
        return;
    }
    solve(head->next, pos, ans);
    if (pos == 0)
    {
        ans = head->data;
    }
    pos--;
}

int main()
{
    system("cls");
    Node *head = NULL;
    Node *tail = NULL;

    head = insertAtHead(1, head, tail);
    head = insertAtHead(2, head, tail);
    head = insertAtHead(3, head, tail);
    head = insertAtHead(4, head, tail);
    head = insertAtHead(5, head, tail);
    print(head);
    cout << getNodeValue(head, 2);
    int ans = -1;
    int pos = 2;
    solve(head, pos, ans);
    cout << endl
         << ans << endl;
    return 0;
}