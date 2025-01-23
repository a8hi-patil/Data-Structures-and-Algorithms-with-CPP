#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int value)
    {
        this->val = value;
        this->next = NULL;
    }
};
void insertAtHead(int value, ListNode *&head, ListNode *&tail)
{
    if (head == NULL && tail == NULL)
    {
        ListNode *newNode = new ListNode(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode *newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
    }
}
void print(ListNode *head)
{
    ListNode *currentNode = head;
    while (currentNode != NULL)
    {
        cout << currentNode->val << "->";
        currentNode = currentNode->next;
    }
    cout << "NULL" << endl;
}
void insertAtTail(int value, ListNode *&head, ListNode *&tail)
{
    if (tail == NULL)
    {
        ListNode *newNode = new ListNode(value);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode *newNode = new ListNode(value);
        tail->next = newNode;
        tail = newNode;
    }
}
int getLength(ListNode *&head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> ans;

    int len = getLength(head);
    int extras = len % k;

    ListNode *start = head;
    for (int i = 0; i < k; i++)
    {
        int bucketSize = extras > 0 ? k + 1 : k;
        extras--;
        ans.push_back(start);
        ListNode *prev = head;
        while (bucketSize && start)
        {
            prev = start;
            start = start->next;
            bucketSize--;
        }
        prev->next = NULL;
    }

    return ans;
}
int main()
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int k = 3;
    insertAtHead(1, head, tail);
    insertAtHead(2, head, tail);
    insertAtHead(3, head, tail);
    insertAtHead(4, head, tail);
    insertAtHead(5, head, tail);
    insertAtHead(6, head, tail);
    insertAtHead(7, head, tail);
    insertAtHead(8, head, tail);
    insertAtHead(9, head, tail);
    insertAtHead(10, head, tail);
    vector<ListNode *> ans = splitListToParts(head, k);

    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
        cout << "-----" << endl;
    }
    return 0;
}