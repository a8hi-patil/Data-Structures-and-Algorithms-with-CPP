#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *bottom;
    Node(int val)
    {
        this->data = val;
        this->bottom = NULL;
        this->next = NULL;
    }
};
Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    Node *ans = NULL;
    if (a->data <= b->data)
    {
        ans = a;
        ans->bottom = merge(a->next, b);
    }
    else
    {
        ans = b;
        ans->bottom = merge(a, b->next);
    }
    return ans;
}
Node *insertAthead(int val, Node *head, Node *tail)
{
    Node *newNode = new Node(val);
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->bottom;
    }
    cout << "NULL" << endl;
}
Node *flatten(Node *root)
{
    if (!root)
        return NULL;
    Node *mergedLL = merge(root, flatten(root->next));
    return mergedLL;
}
int main()
{
    system("cls");
    Node *h1 = NULL;
    Node *h2 = NULL;
    Node *t1 = NULL;
    Node *t2 = NULL;
    h1 = insertAthead(5, h1, t1);
    h1 = insertAthead(3, h1, t1);
    h1 = insertAthead(1, h1, t1);
    h2 = insertAthead(6, h2, t2);
    h2 = insertAthead(4, h2, t2);
    h2 = insertAthead(2, h2, t2);
    Node *ans = merge(h1, h2);
    print(ans);
    return 0;
}